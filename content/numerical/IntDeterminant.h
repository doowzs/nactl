/**
 * Author: Unknown
 * Date: 2014-11-27
 * Source: somewhere on github
 * Description: 使用Gauss消元法（整数计算）求行列式并取模。将取模删了就获得普通的求行列式算法。
 * Status: bruteforce-tested for N <= 3, mod <= 7
 * Time: $O(N^3)$
 */
#pragma once

const ll mod = 12345;
ll det(vector<vector<ll>>& a) {
	int n = sz(a); ll ans = 1;
	rep(i,0,n) {
		rep(j,i+1,n) {
			while (a[j][i] != 0) { // gcd step
				ll t = a[i][i] / a[j][i];
				if (t) rep(k,i,n)
					a[i][k] = (a[i][k] - a[j][k] * t) % mod;
				swap(a[i], a[j]);
				ans *= -1;
			}
		}
		ans = ans * a[i][i] % mod;
		if (!ans) return 0;
	}
	return (ans + mod) % mod;
}
