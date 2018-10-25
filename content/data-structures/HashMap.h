/**
 * Author: Simon Lindholm
 * Date: 2018-07-23
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: 与 unordered\_map 相同的Hashing方式，但是效率大约是 3 倍。
 * 如果提供了初始的容量，必须是2的幂级数。注意在CF等有hack的平台上最好别用。
 */
#pragma once

#include <bits/extc++.h> /** keep-include */
__gnu_pbds::gp_hash_table<ll, int> h({},{},{},{}, {1 << 16});

/** For CodeForces, or other places where hacking might be a problem:
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(ll x) const { return x ^ RANDOM; }
};
__gnu_pbds::gp_hash_table<ll, int, chash> h({},{},{},{}, {1 << 16});
*/
