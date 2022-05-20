/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi13_travel
 * ALGO		: Dijkstra
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

struct Node{
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

const int MxN = 10010;
vector<pair<int, int>> adj[MxN];
int dist[2][MxN];
priority_queue<Node> pq;

inline void dijkstra(int stp, int state){
	dist[state][stp] = 0;
	pq.emplace(stp, 0);
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			if(dist[state][x.first] > nxt){
				pq.emplace(x.first, dist[state][x.first] = nxt);
			}
		}
	}
}

inline void solution(){
	int n, m, x, y, z, u, v, w;
	cin >> n >> m >> x >> y >> z;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dijkstra(x, 0); dijkstra(y, 1);
	dbg(to_string(dist[0], 0, n));
	dbg(to_string(dist[1], 0, n));
	int a = -1e9 - 100, b = 1e9 + 100, c = -1;
	for(int i=0; i<=n; ++i){
		if(dist[0][i] <= z && dist[0][i] >= a && dist[1][i] < b){
			a = dist[0][i];
			b = dist[1][i];
			c = i;
		}
	}
	cout << c << " " << a << " " << b;
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
