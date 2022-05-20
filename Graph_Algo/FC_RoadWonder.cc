/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Road Wonder
 * ALGO		: Bellman Ford
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

struct Edge{
	int u, v, w;
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 1010;
vector<Edge> edges;
int n, dist[2][MxN], stp;

inline void solution(){
	memset(dist[0], 0x3f, sizeof dist[0]);
	cin >> stp;
	dist[0][stp] = 0;
	for(int i=1; i<n; ++i){
		for(auto x: edges){
			dist[0][x.v] = min(dist[0][x.v], dist[0][x.u] + x.w);
		}
	}
	memcpy(dist[1], dist[0], sizeof dist[0]);
	for(auto x: edges){
		dist[1][x.v] = min(dist[1][x.v], dist[1][x.u] + x.w);
	}
	for(int i=1; i<=n; ++i){
		if(dist[0][i] != dist[1][i] || dist[0][i] >= 1e9 + 100){
			cout << -1;
		}
		else{
			cout << dist[0][i];
		}
		cout << " ";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int m, k, q = 1, u, v, w;
	cin >> n >> m >> k >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	for(int i=1; i<=k; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, -w);
	}
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
