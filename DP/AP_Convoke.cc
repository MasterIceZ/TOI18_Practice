/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Convoke 
 * ALGO		: Bitmasks, Floyd Warshall, Dijkstra
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

struct Node{
	int v, w, bit;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c): v(a), w(b), bit(c) {}
};

const int MxN = 220;
vector<pair<int, int>> adj[MxN];
int idx[MxN], dist[MxN][1 << 15];
bitset<MxN> peat_at;
priority_queue<Node> pq; 

inline void solution(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0, x; i<k; ++i){
		cin >> x;
		idx[x] = i;
		peat_at[x] = true;
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<=n; ++i){
		dist[i][i] = 0;
	}
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[v][u], w);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		if(!peat_at[i]){
			continue;
		}
		adj[i].emplace_back(1, dist[1][i]);
		adj[1].emplace_back(i, dist[1][i]);
		adj[n].emplace_back(i, dist[i][n]);
		adj[i].emplace_back(n, dist[i][n]);
		for(int j=i+1; j<=n; ++j){
			if(!peat_at[j]){
				continue;
			}
			adj[i].emplace_back(j, dist[i][j]);
			adj[j].emplace_back(i, dist[i][j]);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, 0, 0);
	dist[1][0] = 0;
	int want = (1 << k) - 1;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		dbg(now.v, now.bit, now.w);
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			int nxt_bit = now.bit | (peat_at[x.first] ? (1 << idx[x.first]): 0);
			if(dist[x.first][nxt_bit] > nxt){
				pq.emplace(x.first, dist[x.first][nxt_bit] = nxt, nxt_bit);
			}
		}
	}
	cout << dist[n][want];
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
