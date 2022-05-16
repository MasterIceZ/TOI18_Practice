/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tension 6
 * ALGO		: Dynamic Programming, Tree
 * DATE		: 15 May 2022
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
vector<pair<int, int>> adj[MxN];
int dp[MxN];

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dfs(x.first, u);
		dp[u] += x.second + dp[x.first];
	}
}

void dfs2(int u, int p){
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dp[x.first] = dp[u] + (x.second? -1: 1);
		dfs2(x.first, u);
	}
}

inline void solution(){
	int n, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v, 0);
		adj[v].emplace_back(u, 1);
	}
	// dp[i] = number of forbidden edges needed
	dfs(1, 1);
	// dp[i] = number of warps needed if start at #i
	dfs2(1, 1);
	int idx = -1, res = 1e9 + 100;
	for(int i=1; i<=n; ++i){
		if(res > dp[i]){
			res = dp[i];
			idx = i;
		}
	}
	cout << res << " " << idx;
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
