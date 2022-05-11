/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi14_nbk48
 * ALGO		: Dynamic Programming, Binary Search
 * DATE		: 7 May 2022
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

const int MxN = 100010;
int dp[MxN];

inline void solution(){
	int n, q, x;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
	for(int i=n-1; i>=1; --i){
		dp[i] = min(dp[i + 1], dp[i]);
	}
	while(q--){
		cin >> x;
		cout << upper_bound(dp + 1, dp + n + 1, x) - (dp + 1) << "\n";
	}
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
