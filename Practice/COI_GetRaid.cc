/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: COI Get Raid
 * ALGO		: Minimum Spanning Tree
 * DATE		: 23 May 2022
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
		return w < o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 100010;
vector<Edge> edges;
int p[MxN], a[MxN];

int fr(int u){
	return u == p[u]?u : p[u]=fr(p[u]);
}

inline void solution(){
	int u, v, n, m, res = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cin >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		edges.emplace_back(u, v, a[u] + a[v]);
	}
	iota(p + 1, p + n + 1, 1);
	sort(edges.begin(), edges.end());
	for(auto x: edges){
		int ru = fr(x.u), rv = fr(x.v);
		if(ru == rv){
			continue;
		}
		res += x.w;
		p[ru] = rv;
	}
	cout << res;
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
