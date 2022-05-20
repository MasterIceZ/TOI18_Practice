/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Lucky
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
	int v, w, state;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c): v(a), w(b), state(c) {}
};

const int MxN = 50050;
int n, m, l, s, e, a[MxN], dist[MxN][33];
vector<pair<int, int>> adj[MxN];
priority_queue<Node> pq;

inline void solution(){
	cin >> n >> m >> l >> s >> e;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[s][0] = 0;
	pq.emplace(s, 0, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			if(now.state + 1 == a[x.first] && dist[x.first][now.state + 1] > nxt){
				pq.emplace(x.first, dist[x.first][now.state + 1] = nxt, now.state + 1);
			}
			else if(dist[x.first][now.state] > nxt){
				pq.emplace(x.first, dist[x.first][now.state] = nxt, now.state);
			}
		}
	}
	cout << (dist[e][l] >= 1e9 + 100 ? -1: dist[e][l]);
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
