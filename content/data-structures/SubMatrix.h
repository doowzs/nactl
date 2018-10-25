/**
 * Date: 2014-11-28
 * Author: Johan Sannemo
 * License: CC0
 * Source: Folklore
 * Status: Tested on Kattis
 * Description: 给出二维数组(vector<vector<T>>)的两个坐标，计算两坐标构成的矩形中所有元素的和。
 * Usage:
 * SubMatrix<int> m(matrix);
 * m.sum(0, 0, 2, 2); // 左上角的四个元素
 * Time: O(N^2 + Q)
 */
#pragma once

template<class T>
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		p.assign(R+1, vector<T>(C+1));
		rep(r,0,R) rep(c,0,C)
			p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
	}
	T sum(int u, int l, int d, int r) {
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};
