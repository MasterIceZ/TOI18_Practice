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

struct Query{
	int st, ed, w, idx;
	bool state = false;
	bool operator < (const Query& o) const {
		return w < o.w;
	}
};

inline bool cmp(const Query A, const Query B){
	return A.idx < B.idx;
}

const int MxN = 100010;
vector<Edge> edges;
Query query[2 * MxN];
int p[MxN];
vector<pair<int, int>> adj[MxN];

int fr(int u){
	return u == p[u]? u: p[u] = fr(p[u]);
}

inline void solution(){
	int n, m, q, u, v, w;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	iota(p + 1, p + n + 1, 1);
	sort(edges.begin(), edges.end());
	for(int i=1; i<=q; ++i){
		cin >> query[i].st >> query[i].ed >> query[i].w;
		query[i].idx = i;
	}
	sort(query + 1, query + q + 1);
	int it = 1, maxx = 0;
	for(auto x: edges){
		int ru = fr(x.u), rv = fr(x.v);
		if(ru == rv){
			continue;
		}
		while(it <= n && x.w > query[it].w){
			if(fr(query[it].st) == fr(query[it].ed)){
				dbg(query[it].st, query[it].ed);
				query[it].state = true;
			}
			it++;
		}
		p[ru] = rv;
		maxx = max(maxx, x.w);
	}
	while(it <= n){
		if(query[it].w >= maxx){
			query[it].state = true;
		}
		it++;
	}
	sort(query + 1, query + q + 1, cmp);
	for(int i=1; i<=q; ++i){
		cout << (query[i].state? "Yes": "No") << "\n";
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
