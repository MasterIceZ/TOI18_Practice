/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_beehive
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

const int MxN = 1010;
int dp[MxN][MxN], cnt[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cnt[1][i] = 1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> dp[i][j];
		}
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(i % 2){
				int toadd = max(dp[i - 1][j], dp[i - 1][j - 1]);
				dp[i][j] += toadd;
				if(toadd == dp[i - 1][j]){
					cnt[i][j] += cnt[i - 1][j];
				}
				if(toadd == dp[i - 1][j - 1]){
					cnt[i][j] += cnt[i - 1][j - 1];
				}
			}
			else{
				int toadd = max(dp[i - 1][j], dp[i - 1][j + 1]);
				dp[i][j] += toadd;
				if(toadd == dp[i - 1][j]){
					cnt[i][j] += cnt[i - 1][j];
				}
				if(toadd == dp[i - 1][j + 1]){
					cnt[i][j] += cnt[i - 1][j + 1];
				}
			}
		}
	}
	int maxx = 0, answer = 0;
	for(int i=1; i<=m; ++i){
		if(dp[n][i] > maxx){
			maxx = dp[n][i];
			answer = 0;
		}
		if(maxx == dp[n][i]){
			answer += cnt[n][i];
		}
	}
	cout << maxx << " " << answer;
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
