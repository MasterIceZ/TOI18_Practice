/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_place
 * ALGO		: Minimum Spanning Tree, Kruskal's Algorithm
 * DATE		: 13 May 2022
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
	int u, v;
	ll w;
	Edge(int a, int b, ll c): u(a), v(b), w(c) {}
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
};

const int MxN = 200020;
int p[MxN];

int fr(int u){
	return p[u] == u? u: p[u] = fr(p[u]);
}

inline void solution(){
	int n, m, u, v;
	ll cnt = 0ll, w;
	cin >> n >> m;
	vector<Edge> edges;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	iota(p + 1, p + n + 1, 1);
	sort(edges.begin(), edges.end());
	for(auto x: edges){
		int ru = fr(x.u), rv = fr(x.v);
		if(ru == rv){
			continue;
		}
		p[ru] = rv;
		cnt += x.w - 1ll;
	}
	cout << cnt;
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
