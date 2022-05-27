/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Stocks
 * ALGO		: Dynamcic Programming
 * DATE		: 24 May 2022
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

const int MxN = 1000010;
int n, dp[MxN][4];

inline void solution(){
	cin >> n;
	memset(dp, 0, sizeof dp);
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = -1e9 - 100;
	int answer = 0;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		dp[i][0] = max(dp[i - 1][0], -x);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + x);
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - x);
		dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + x);
		answer = max({answer, dp[i][0], dp[i][1], dp[i][2], dp[i][3]});
	}
	cout << answer;
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
