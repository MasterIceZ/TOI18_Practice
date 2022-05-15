/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_cablecar
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
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 2505;
int pr[MxN];

int fr(int u){
	return u == pr[u]? u: pr[u] = fr(pr[u]);
}

inline void solution(){
	int n, m, s, p, d, u, v, w;
	cin >> n >> m;
	vector<Edge> edges;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	sort(edges.begin(), edges.end());
	iota(pr + 1, pr + n + 1, 1);
	cin >> s >> d >> p;
	for(auto x: edges){
		int ru = fr(x.u), rv = fr(x.v);
		if(ru == rv){
			continue;
		}
		pr[ru] = rv;
		if(fr(s) == fr(d)){
			cout << fixed << setprecision(0) << ceil(p * 1.0 / (x.w - 1));
			return ;
		}
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
