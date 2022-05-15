/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tahakashi and Animals
 * ALGO		: Dynamic Programming
 * DATE		: 14 May 2022
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

const int MxN = 300030;
ll a[MxN], b[MxN], dp[MxN][3];

// dp[i][0] = use this
// dp[i][1] = use last

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = a[1];
	for(int i=2; i<=n; ++i){
		dp[i][1] = dp[i - 1][0];
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
	}
	ll res = min(dp[n][0], dp[n][1]);

	// shift 1 -> 2, 2 -> 3, ..., N -> 1
	memcpy(b, a, sizeof a);
	for(int i=1; i<=n; ++i){
		a[i] = b[(i - 2 + n) % n + 1];
	}

	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = a[1];
	for(int i=2; i<=n; ++i){
		dp[i][1] = dp[i - 1][0];
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
	}
	res = min({res, dp[n][0], dp[n][1]});
	
	cout << res;
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
