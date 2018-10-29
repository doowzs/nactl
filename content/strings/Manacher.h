/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: 本函数计算p数组，其中p[0][i]表示以i(+1/2)为中心的偶数长的回文串的半长；p[1][i]表示以i为中心的奇数长的回文串的半长（向下取整）。
 * Time: O(N)
 * Status: Fuzz-tested
 */
#pragma once

void manacher(const string& s) {
	int n = sz(s);
	vi p[2] = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
}
