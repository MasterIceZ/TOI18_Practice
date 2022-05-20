/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi14_logistics
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
	int v, w, f, u;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c, int d): v(a), w(b), f(c), u(d) {}
};

const int MxN = 110;
vector<pair<int, int>> adj[MxN];
int a[MxN], dist[MxN][MxN][2];

inline void solution(){
	int n, s, e, d, m, u, v, w;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cin >> s >> e >> d >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.emplace(s, 0, 0, 0);
	dist[s][0][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		// fill tank
		int nxt = now.w + a[now.v];
		if(now.f + 1 <= d && dist[now.v][now.f + 1][now.u] > nxt){
			pq.emplace(now.v, dist[now.v][now.f + 1][now.u] = nxt, now.f + 1, now.u);
		}
		if(!now.u && dist[now.v][d][1] > now.w){
			pq.emplace(now.v, dist[now.v][d][1] = now.w, d, 1);
		}
		for(auto x: adj[now.v]){
			int nxt = now.w, nxt_f = now.f - x.second;
			if(nxt_f >= 0 && dist[x.first][nxt_f][now.u] > nxt){
				pq.emplace(x.first, dist[now.v][nxt_f][now.u] = nxt, nxt_f, now.u);
			}
		}
	}
	cout << dist[e][d][1];
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
