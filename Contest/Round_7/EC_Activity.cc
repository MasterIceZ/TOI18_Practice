/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 150050;
int dp[MxN][4], a[MxN], b[MxN], c[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int j=1; j<=n; ++j){
		cin >> b[j];
	}
	for(int k=1; k<=n; ++k){
		cin >> c[k];
	}
	// 1, 2, 3
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + a[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + c[i];
	}
	int answer = dp[n][2];
	// 1, 3, 2
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + a[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + c[i];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + b[i];
	}
	answer = min(answer, dp[n][2]);
	// 2, 1, 2
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + b[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + c[i];
	}
	answer = min(answer, dp[n][2]);
	// 2, 3, 1
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + b[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + c[i];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + a[i];
	}
	answer = min(answer, dp[n][2]);
	// 3, 1, 2
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + c[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + b[i];
	}
	answer = min(answer, dp[n][2]);
	// 3, 2, 1
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + c[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + a[i];
	}
	answer = min(answer, dp[n][2]);
	cout << answer;
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
