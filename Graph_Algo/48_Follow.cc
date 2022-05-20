/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Follow
 * ALGO		: Dijkstra, Depth First Search
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

struct Edge{
	int v, w, idx;
	Edge(int a, int b, int c): v(a), w(b), idx(c) {}
};

struct Node{
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

using ll = long long;
using pii = pair<int, int>;
const int MxN = 1010;

vector<Edge> adj[MxN];
vector<int> peat_path;
stack<pii> st;
unordered_map<int, pii> use_path; // stores start time and end time
priority_queue<Node> pq;
int n, m, s, e, t, p, u, v, w, dist[MxN];

inline void dfs(){
	st.emplace(peat_path[0], 0);
	int it = 0;
	while(!st.empty()){
		pair<int, int> now = st.top();
		st.pop();
		if(it + 1 == p){
			break;
		}
		for(auto x: adj[now.first]){
			if(x.v != peat_path[it + 1]){
				continue;
			}
			use_path[x.idx] = make_pair(now.second, now.second + x.w);
			st.emplace(x.v, now.second + x.w);
			it++;
			break;
		}
	}
	while(!st.empty()){
		st.pop();
	}
}

inline void solution(){
	use_path.clear();
	cin >> n >> m >> s >> e >> t >> p;
	peat_path.clear();
	for(int i=1, x; i<=p; ++i){
		cin >> x;
		peat_path.emplace_back(x);
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w, i);
		adj[v].emplace_back(u, w, i);
	}
	dfs();
	memset(dist, 0x3f, sizeof dist);
	dist[s] = t;
	pq.emplace(s, t);
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + x.w;
			// check in used -> wait!
			if(use_path.find(x.idx) != use_path.end() && now.w >= use_path[x.idx].first && now.w < use_path[x.idx].second){
				nxt = use_path[x.idx].second + x.w;
			}
			if(dist[x.v] > nxt){
				pq.emplace(x.v, dist[x.v] = nxt);
			}
		}
	}
	cout << dist[e] - t;
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
