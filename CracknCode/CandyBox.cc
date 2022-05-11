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

const int MOD = 1e9 + 7;
const int MxN = 1010;
int dp[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=1000; ++i){
		dp[1][i] = 1;
		dp[i][0] = 1;
	}
	for(int i=2; i<=1000; ++i){
		for(int j=1; j<=1000; ++j){
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + 1) % MOD;
		}
	}
	cout << dp[n][m];
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
