#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../content/numerical/FastSubsetTransform.h"

int main() {
	rep(k,0,10) {
		vi a(1 << k), b = a, c = a, target = a;
		trav(x, a) x = rand() % 6 - 2;
		trav(x, b) x = rand() % 6 - 2;
		rep(i,0,1 << k) rep(j,0,1 << k) target[i & j] += a[i] * b[j];
		// rep(i,0,1 << k) cout << a[i] << ' '; cout << endl;
		// rep(i,0,1 << k) cout << b[i] << ' '; cout << endl;
		FST(a, false);
		FST(b, false);
		rep(i,0,1 << k) c[i] = a[i] * b[i];
		FST(c, true);
		// rep(i,0,1 << k) cout << c[i] << ' '; cout << endl;
		// rep(i,0,1 << k) cout << target[i] << ' '; cout << endl;
		assert(c == target);
	}
}
