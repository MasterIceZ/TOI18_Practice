/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Follower
 * ALGO		: Breadth First Search
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

const int MxN = 110;
bool visited[MxN][1030];
vector<pair<int, int>> adj[MxN];

inline void solution(){
	int n, m, s, e, u, v, w;
	cin >> n >> m >> s >> e;
	memset(visited, false, sizeof visited);
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	queue<pair<int, int>> q;
	q.emplace(s, 0);
	visited[s][0] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(auto x: adj[now.first]){
			int nxt = now.second ^ x.second;
			if(visited[x.first][nxt]){
				continue;
			}
			visited[x.first][nxt] = true;
			q.emplace(x.first, nxt);
		}
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	for(int i=0; i<=1024; ++i){
		if(visited[e][i]){
			cout << i;
			break;
		}
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
