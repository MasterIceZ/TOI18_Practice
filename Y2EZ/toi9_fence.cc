/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_fence
 * ALGO		: Dynamic Programming
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

const int MxN = 550;
int dp[MxN][MxN];

inline void solution(){
	memset(dp, 0, sizeof dp);
	int n, m, k, x, y;
	cin >> n >> m >> k;
	while(k--){
		cin >> x >> y;
		dp[x + 1][y + 1] = 1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int max_size = min(n, m), answer = 0;
	for(int k=max_size; k>=0; --k){
		for(int i=k; i<=n; ++i){
			for(int j=k; j<=m; ++j){
				int in = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
				int out = dp[i - 1][j - 1] - dp[i - k + 1][j - 1] - dp[i - 1][j - k + 1] + dp[i - k + 1][j - k + 1];
				if(in == out){
					answer = max(answer, k);
				}
			}
		}
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 2;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
