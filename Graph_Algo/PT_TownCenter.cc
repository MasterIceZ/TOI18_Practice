/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Town Center
 * ALGO		: Minimum Spanning Tree, Kruskal's Algorithm
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

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 1010;
int n, x, maxx, it, parent[MxN], deg[MxN];
vector<Edge> edges;

int find_root(int u){
	return u == parent[u]? u: parent[u] = find_root(parent[u]);
}

inline void solution(){
	edges.clear();
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> x;
			if(i <= j){
				continue;
			}
			edges.emplace_back(i, j, x);
		}
	}
	memset(deg, 0, sizeof deg);
	iota(parent + 1, parent + n + 1, 1);
	sort(edges.begin(), edges.end());
	for(auto x: edges){
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv){
			continue;
		}
		deg[x.u]++, deg[x.v]++;
		parent[ru] = rv;
	}
	maxx = 0, it = 0;
	for(int i=1; i<=n; ++i){
		if(deg[i] > maxx){
			maxx = deg[i], it = i;
		}
	}
	cout << it << " " << maxx;
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
