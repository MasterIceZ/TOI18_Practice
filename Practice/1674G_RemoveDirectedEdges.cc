/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Remove Directed Edges
 * ALGO		: Dynamic Programming, Tree
 * DATE		: 11 May 2022
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

const int MxN = 200020;
int in[MxN], out[MxN], dp[MxN];
vector<int> adj[MxN];

void dfs(int u){
	if(in[u] >= 2 && out[u] >= 2){
		dp[u] = 1;
		for(auto x: adj[u]){
			if(dp[x] == -1){
				dfs(x);
			}
			dp[u] = max(dp[u], dp[x] + 1);
		}
		return ;
	}
	if(in[u] >= 2){
		dp[u] = 1;
		return ;
	}
	dp[u] = -1e9 - 100;
}

inline void solution(){
	int u, v, n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		in[v]++, out[u]++;
	}
	memset(dp, -1, sizeof dp);
	int answer = 1;
	for(int i=1; i<=n; ++i){
		if(out[i] < 2){
			continue;
		}
		for(auto x: adj[i]){
			if(dp[x] == -1){
				dfs(x);
			}
			answer = max(answer, dp[x + 1] + 1);
		}
	}
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
