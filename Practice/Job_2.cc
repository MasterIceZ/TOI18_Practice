/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Job
 * ALGO		:
 * DATE		: 22 May 2022
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

const int MxN = 25;
int dp[1 << MxN];
vector<int> bit[MxN];

inline void solution(){
	int n, k;
	cin >> n;
	int ms = (1 << n) - 1, b;
	for(int i=1; i<=ms; ++i){
		bit[__builtin_popcount(i)].emplace_back(i);
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<n; ++j){
			cin >> k;
			b = 1 << j;
			for(auto x: bit[i]){
				if(!(x & b)){
					continue;
				}
				dp[x] = min(dp[x], dp[x ^ b] + k);
			}
		}
	}
	cout << dp[ms];
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
