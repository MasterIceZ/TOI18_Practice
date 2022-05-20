/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Tree Subset
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

const int MxN = 100010;
ll v[MxN], dp[2][MxN];
// dp[0][u] => not use in this state
// dp[1][u] => use in this state
vector<int> adj[MxN];

void dfs(int u, int p){
	dp[1][u] = v[u];
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		dp[0][u] += max(dp[1][x], dp[0][x]);
		dp[1][u] += dp[0][x];
	}
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}	
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	memset(dp, 0, sizeof dp);
	dfs(1, 1);
	cout << max(dp[0][1], dp[1][1]);
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
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
