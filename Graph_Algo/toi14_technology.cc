/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi14_technology
 * ALGO		: Depth First Search
 * DATE		: 20 May 2022
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
int time_left;
vector<int> adj[MxN], level[2 * MxN];
bitset<MxN> visited, visited_2;

void dfs(int u){
	if(visited_2[u]){
		time_left = 0;
		return ;
	}
	visited_2[u] = true;
	for(auto x: adj[u]){
		if(visited[x]){
			continue;
		}
		dfs(x);
	}
	visited[u] = true;
	time_left -= 1;
}

inline void solution(){
	int n, k, t;
	cin >> n >> k >> t;
	time_left = t;
	for(int i=1, m, x; i<=n; ++i){
		cin >> x >> m;
		level[x].emplace_back(i);
		for(int j=1, v; j<=m; ++j){
			cin >> v;
			adj[i].emplace_back(v);
		}
	}
	int answer = 1;
	for(int i=1; i<=k; ++i){
		for(auto x: level[i]){
			if(visited[x]){
				continue;
			}
			dfs(x);
		}
		if(time_left <= 0){
			answer = i - (time_left < 0);
			break;
		}
	}
	cout << (answer == 0? -1: answer);
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
