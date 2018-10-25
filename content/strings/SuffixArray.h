/**
 * Author: Lukas Polacek
 * Date: 2009-10-27
 * License: CC0
 * Source: folklore and Linear-time longest-common-prefix
 * computation in suffix arrays and its applications (2001).
 * Description: 计算后缀数组。$a[i]$表示第$i$大的后缀的起始位置，$a[0] = n$。
 * {\tt lcp}计算后缀数组中相邻字符串的最长公共前缀。返回数组的大小为$n+1$，$ret[0] = 0$。
 * Time: $O(N \log^2 N)$ where $N$ is the length of the string
 * for creation of the SA. $O(N)$ for longest common prefixes.
 * Memory: $O(N)$
 * Status: Tested on UVa Live 4513
 */
#pragma once

typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) { // (optional)
	// N=10^6时，比STL的排序快3倍
	int mask = (1 << bits) - 1;
	rep(it,0,2) {
		int move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		rep(i,0,sz(b))
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pli> res(b.size());
		rep(i,0,sz(b))
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pli> b(N);
		a.resize(N);
		rep(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // 也可以用sort(all(b))
			a[b[0].second] = 0;
			rep(i,1,N)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			rep(i,0,N) {
				b[i].first = (ll)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	vi lcp() {
		// 计算最长公共前缀： res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		rep(i,0,n) inv[a[i]] = i;
		rep(i,0,n) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};
