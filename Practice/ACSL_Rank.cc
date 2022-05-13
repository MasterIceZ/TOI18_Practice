/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Rank
 * ALGO		: Kosaraju's Algorithm
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

const int MxN = 22;
vector<int> adj[MxN], rev[MxN];
stack<int> st;
bitset<MxN> visited;
int comp[MxN], cnt[MxN];

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs(x, u);
	}
	st.emplace(u);
}

void dfs2(int u, int p, int id){
	visited[u] = true;
	comp[u] = id;
	cnt[id]++;
	for(auto x: rev[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs2(x, u, id);
	}
}

inline void solution(){
	int n, m, u, v, su, sv;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> su >> sv;
		if(su > sv){
			adj[u].emplace_back(v);
			rev[v].emplace_back(u);
		}
		else{
			adj[v].emplace_back(u);
			rev[u].emplace_back(v);
		}
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			dfs(i, 0);
		}
	}
	visited = 0;
	int it = 0, answer = 0;
	while(!st.empty()){
		int now = st.top();
		st.pop();
		if(visited[now]){
			continue;
		}
		dfs2(now, 0, ++it);
		answer += (cnt[it] <= 1 ? 0: cnt[it]);
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
