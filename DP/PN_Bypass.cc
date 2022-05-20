/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Bypass
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
vector<int> adj[MxN];
ll dp[MxN], mem[MxN][2][2], n, answer;
bool ok = false;

// mem[i][j][k] -> node[i] with [j] {0(most), 1(2nd most)} and [k] {0(value), 1(index)} 

inline void pass(int idx){
	mem[idx][1][0] = mem[idx][0][0];
	mem[idx][1][1] = mem[idx][0][1];
}

void sum(int u, int p){
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		sum(x, u);
		dp[u] += dp[x];
		if(mem[u][0][0] < dp[x]){
			pass(u);
			mem[u][0][0] = dp[x];
			mem[u][0][1] = x;
		}
		else if(mem[u][1][0] < dp[x]){
			mem[u][1][0] = dp[x];
			mem[u][1][1] = x;
		}
	}
}

void dfs(int u, int p){
	if(ok){
		dp[p] = n - dp[u];
		if(mem[u][0][0] < dp[p]){
			pass(u);
			mem[u][0][0] = dp[p];
			mem[u][0][1] = p;
		}
		else if(mem[u][1][0] < dp[p]){
			mem[u][1][0] = dp[p];
			mem[u][1][1] = p;
		}
	}
	ok = true;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dbg(mem[u][0][1], x, mem[u][0][0], mem[u][1][0], mem[x][0][0]);
		if(mem[u][0][1] != x){
			answer = max(answer, mem[u][0][0] * mem[x][0][0]);
		}
		else{
			answer = max(answer, mem[u][1][0] * mem[x][0][0]);
		}
	}
}

inline void solution(){
	memset(mem, 0, sizeof mem);
	answer = 0ll;
	cin >> n;		
	for(int i=1; i<=n; ++i){
		dp[i] = 1ll;
	}
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	sum(1, 1);
	dbg(to_string(dp, 1, n));
	ok = false;
	dfs(1, 1);
	cout << answer;
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
