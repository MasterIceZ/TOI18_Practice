/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Silver
 * ALGO		: Dynamic Programming, Tree, Disjoint Set Union
 * DATE		: 26 May 2022
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
vector<int> adj[MxN];
int p[MxN], dp[MxN][2], mem[MxN], res;
bitset<MxN> visited;

int fr(int u){
	return u == p[u]? u: p[u] = fr(p[u]);
}

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs(x, u);
		int ru = fr(u), rx = fr(x);
		::p[rx] = ru;
		if(dp[x][0] + 1 > dp[u][0]){
			dp[u][1] = dp[u][0];
			dp[u][0] = dp[x][0] + 1;
		}
		else if(dp[x][0] + 1 > dp[u][1]){
			dp[u][1] = dp[x][0] + 1;
		}
	}
	res = max(res, dp[u][0] + dp[u][1]);
}

inline void solution(){
	int opr, n, m, q, x, y, u, v;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v); adj[v].emplace_back(u);
	}
	iota(p + 1, p + n + 1, 1);
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		res = 0;
		dfs(i, 0);
		mem[i] = res;
	}
	while(q--){
		cin >> opr;
		if(opr == 1){
			cin >> x;
			cout << mem[fr(x)] << "\n";
		}
		else{
			cin >> x >> y;
			int rx = fr(x), ry = fr(y);
			if(rx == ry){
				continue;
			}
			mem[rx] = max({mem[rx], mem[ry], (mem[ry] + 1) / 2 + (mem[rx] + 1) / 2 + 1});
			p[ry] = rx;
		}
	}
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
