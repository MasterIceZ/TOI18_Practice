/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48 Fight
 * ALGO		: Bipartite Graph, Search By Elimination
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

const int MxN = 100100;
vector<pair<int, int>> adj[MxN];
int color[MxN];
queue<int> q;

inline bool ok(int idx){
	while(!q.empty()){
		q.pop();
	}
	memset(color, 0, sizeof color);
	color[1] = 1;
	q.emplace(1);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto x: adj[now]){
			if(x.second > idx){
				continue;
			}
			if(color[x.first] && color[x.first] != 3 - color[now]){
				return false;
			}
			if(!color[x.first]){
				q.emplace(x.first);
				color[x.first] = 3 - color[now];
			}
		}
	}
	return true;
}

inline void solution(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}
	int l = 1, r = m;
	while(l < r){
		int mid = (1 + l + r) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << 1 + l;
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
