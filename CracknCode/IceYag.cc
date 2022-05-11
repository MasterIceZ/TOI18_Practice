/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Ice Yag
 * ALGO		: Minimum Spanning Tree
 * DATE		: 7 May 2022
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
int p[MxN];

int fr(int u){
	if(u == p[u]){
		return u;
	}
	return p[u] = fr(p[u]);
}

inline void solution(){
	int u, v, w, n, m, s, e;
	cin >> n >> m >> s >> e;
	vector<int> states;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
		states.emplace_back(w);
	}
	sort(edges.begin(), edges.end());
	sort(states.begin(), states.end());
	states.resize(unique(states.begin(), states.end()) - states.begin());
	int res = 1e9 + 100;
	for(auto state: states){
		iota(p + 1, p + n + 1, 1);
		int minn = 1e9 + 100;
		for(auto x: edges){
			int ru = fr(x.u), rv = fr(x.v);
			if(ru == rv || x.w < state){
				continue;
			}
			p[ru] = rv;
			if(minn = 1e9 + 100){
				minn = x.w;
			}
			if(fr(s) == fr(e)){
				res = min(res, x.w - state);
			}
		}
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
