/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		 :PT_Drink Water
 * ALGO		: Dynamic Programming, Bitmasks
 * DATE		: 18 May 2022
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

const int MxN = 20;
ll dp[1 << MxN], a[MxN][MxN];
// dp[state] = have glass kth in binary of state

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	ll res = 1e18;
	dp[(1 << n) -1] = 0;
	for(int state=(1 << n) - 1; state>=0; --state){
		for(int i=0; i<n; ++i){
			if(!(state & (1 << i))){
				continue;
			}
			for(int j=0; j<n; ++j){
				if(!(state & (1 << j)) || i == j){
					continue;
				}
				int not_have = state ^ (1 << i);
				// pour from i to j
				dp[not_have] = min(dp[not_have], dp[state] + a[i][j]);
			}
		}
	}
	for(int i=0; i<(1 << n); ++i){
		if(__builtin_popcount(i) <= k){
			res = min(res, dp[i]);
		}
	}
	cout << res;
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
