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

struct Edge{
	int u, v, w;
	bool operator < (const Edge &o) const {
		return w < o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

struct Node{
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

const int MxN = 100010;
vector<Edge> edges;
int p[MxN], to_i[MxN], d[MxN];
vector<pair<int, int>> adj[MxN];
priority_queue<Node> pq;

inline void solution(){
	int n, m, q, u, v, w, edp, stp, x;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(d, 0x3f, sizeof d);
	pq.emplace(1, 0);
	d[1] = 0;	
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			if(d[x.first] > x.second){
				d[x.first] = x.second;
				pq.emplace(x.first, x.second);
			}
		}
	}
	while(q--){
		cin >> stp >> edp >> x;
		cout << (max(d[stp], d[edp]) < x? "Yes": "No") << "\n";
	}
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
