/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Best Vegetable
 * ALGO		: Dynamic Programming
 * DATE		: 21 May 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

int x, n, k, l;
const int MxN = 77;
int dp[MxN][MxN * MxN];

inline void solution(){
	memset(dp, 0, sizeof dp);
	cin >> n >> k >> l;
	l = min(n * n, l);
	for(int from=1; from<=n; ++from){
		cin >> x;
		for(int to=min(from, k); to>=1; --to){
			for(int cnt=from-to; cnt<=l; ++cnt){
				dp[to][cnt] = max(dp[to][cnt], x + dp[to - 1][cnt - (from - to)]);
			}
		}
	}
	dbg(to_string(dp[k], 0, l));
	cout << *max_element(dp[k], dp[k] + l + 1);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
