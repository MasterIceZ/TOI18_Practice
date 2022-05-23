/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Tension3
 * ALGO		: 
 * DATE		: 21 May 2022
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

struct Graph{
	int v, w, state;
	Graph(int a, int b, int c): v(a), w(b), state(c) {}
};

struct Node{
	int v, w, state;
	Node(int a, int b, int c): v(a), w(b), state(c) {}
	bool operator < (const Node& o) const {
		return w > o.w;
	}
};

const int MxN = 10010;
const int MxS = 1 << 8;
int dist[MxN][MxS];
vector<Graph> adj[MxN];
priority_queue<Node> pq;

inline void solution(){
	int n, m, a, q, b, k;
	cin >> n >> m >> a >> q;
	for(int i=1, u, v, w, s; i<=m; ++i){
		cin >> u >> v >> w >> s;
		adj[u].emplace_back(v, w, 1 << (s - 1));
		adj[v].emplace_back(u, w, 1 << (s - 1));
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(a, 0, 0);
	dist[a][0] = 0;
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + x.w;
			int nxt_state = now.state | x.state;
			if(dist[x.v][nxt_state] > nxt){
				pq.emplace(x.v, dist[x.v][nxt_state] = nxt, nxt_state);
			}
		}
	}
	while(q--){
		cin >> b >> k;
		int not_come = 0;
		for(int i=1, x; i<=k; ++i){
			cin >> x;
			not_come |= (1 << (x - 1));
		}
		int answer = 1e9 + 200;
		for(int state=0; state<(1 << 8); ++state){
			if(not_come & state){
				continue;
			}
			answer = min(answer, dist[b][state]);
		}
		cout << (answer >= 1e9 + 100 ? -1: answer) << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
