/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_budget
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
		return w < o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 3030;
vector<Edge> edges;
int p[MxN];

int fr(int u){
	return p[u] == u? p[u]: p[u] = fr(p[u]);
}

inline void solution(){
	int n, m, u, v, w, t, x;
	cin >> n >> m;
	iota(p + 1, p + n + 1, 1);
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w >> t;
		if(t){
			p[fr(u)] = fr(v);
		}
		else{
			edges.emplace_back(u, v, w);
		}
	}
	sort(edges.begin(), edges.end());
	cin >> x;
	vector<pair<int, int>> prices;
	for(int i=1, a, b; i<=x; ++i){
		cin >> a >> b;
		prices.emplace_back(a, b);
	}
	prices.emplace_back(0, 0);
	sort(prices.begin(), prices.end());
	for(int i=x-1; i>=0; --i){
		prices[i].second = min(prices[i].second, prices[i + 1].second);
	}
	int res = 0;
	for(auto x: edges){
		int ru = fr(x.u), rv = fr(x.v);
		if(ru == rv){
			continue;
		}
		dbg(x.u, x.v, x.w);
		p[ru] = rv;
		res += (lower_bound(prices.begin(), prices.end(), make_pair(x.w, (int) -1e9 - 100)))->second;
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
