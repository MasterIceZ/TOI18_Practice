/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: NC_Celebration
 * ALGO		: Dynamic Programming, Tree
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

const int MxN = 10010;
vector<int> adj[MxN];
int a[MxN], dp[3][MxN];

void dfs(int u, int p){
	if(dp[2][u] != -1){
		return ;
	}
	dp[1][u] = a[u];
	int s = 0;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		s += dp[2][x];
		dp[1][u] += min(dp[0][x], dp[2][x]);
	}
	dp[0][u] = s;
	dp[2][u] = dp[1][u];
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dp[2][u] = min(dp[2][u], s - dp[2][x] + dp[1][x]);
	}
}

inline void solution(){
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 1);
	cout << dp[2][1];
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
