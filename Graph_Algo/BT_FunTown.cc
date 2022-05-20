/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BT_Fun Town
 * ALGO		: Dijkstra
 * DATE		: 19 May 2022
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

const int MxN = 1000010;
vector<pair<int, int>> adj[MxN];
int dist[MxN];
bitset<MxN> end_point;
priority_queue<Node> pq;

inline void solution(){
	int n, m, x, y, u, v, w;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	end_point = 0;
	cin >> x;
	for(int i=1, k; i<=x; ++i){
		cin >> k;
		dist[k] = 0;
		pq.emplace(k, 0);
	}
	cin >> y;
	for(int i=1, k; i<=y; ++i){
		cin >> k;
		end_point[k] = true;
	}
	int answer = 1e9 + 100;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(end_point[now.v]){
			answer = min(answer, now.w);
		}
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	cout << answer;
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
