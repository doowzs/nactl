/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: 单点更新最大值的线段树。注意查询区间是左闭右开的，即$[b,e)$。通过修改T、LOW、f可以改变线段树的性质。
 * Time: O(\log N)
 * Status: fuzz-tested
 */
#pragma once

struct Tree {
	typedef int T;
	static const T LOW = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
