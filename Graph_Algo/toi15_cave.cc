/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 2020;
int dist[MxN][MxN];
vector<pair<int, int>> adj[MxN];
priority_queue<Node> pq;

inline void solution(){
	int n, st, ed, m, nxt, q, x, u, v, w;
	cin >> n >> st >> ed >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(st, 0, 0);
	dist[st][0] = 0;
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			nxt = now.w + x.second;
			if(now.v == st){
				if(dist[x.first][now.state] > nxt){
					pq.emplace(x.first, dist[x.first][now.state] = nxt, now.state);
				}
			}
			else if(now.v != st && x.first != st){
				if(dist[x.first][now.state + 1] > nxt){
					pq.emplace(x.first, dist[x.first][now.state + 1] = nxt, now.state + 1);
				}
			}
		}
	}
	cin >> q;
	while(q--){
		cin >> x;
		int answer = dist[ed][0];
		for(int i=1; i<n; ++i){
			if(dist[ed][i] >= 1e9 + 100){
				continue;
			}
			answer = min(answer, dist[ed][i] + (i * x));
		}
		cout << answer << " ";
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
