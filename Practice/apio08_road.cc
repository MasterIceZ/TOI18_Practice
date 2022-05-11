/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: APIO8_Roads
 * ALGO		: Minimum Spanning Tree
 * DATE		: 9 May 2922
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

struct Answer{
	int u, v, w;
	Answer(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 20020;
vector<pair<int, int>> road[3], cobble;
vector<int> adj[MxN];
int p[MxN], comp[MxN];

int fr(int u){
	return p[u] == u? u: p[u] = fr(p[u]);
}

inline void noSol(bool x){
	if(!x){
		return ;
	}
	cout << "no solution\n";
	exit(0);
}

void dfs(int u, int it){
	comp[u] = it;
	for(auto x: adj[u]){
		if(comp[x]){
			continue;
		}
		dfs(x, it);
	}
}

inline void solution(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		road[w].emplace_back(u, v);
	}
	iota(p + 1, p + n + 1, 1);
	for(auto x:road[1]){
		int ru = fr(x.first), rv = fr(x.second);
		if(ru == rv){
			continue;
		}
		adj[x.first].emplace_back(x.second);
		adj[x.second].emplace_back(x.first);
		p[ru] = rv;
	}
	int cnt = 0;
	// name node for component
	for(int i=1; i<=n; ++i){
		if(!comp[i]){
			dfs(i, ++cnt);
		}
	}
	noSol(cnt > k);
	iota(p + 1, p + n + 1, 1);
	// Try to merge Components
	for(auto x: road[0]){
		int ru = fr(comp[x.first]), rv = fr(comp[x.second]);
		if(ru == rv){
			continue;
		}
		cnt--;
		cobble.emplace_back(x);
		p[ru] = rv;
	}
	noSol(cnt != 1);
	iota(p + 1, p + n + 1, 1);
	vector<Answer> answer;
	cnt = n;
	for(auto x: cobble){
		answer.emplace_back(x.first, x.second, 0);
		int ru = fr(x.first);
		int rv = fr(x.second);
		if(ru == rv){
			continue;
		}
		cnt--;
		p[ru] = rv;
	}
	for(auto x: road[0]){
		if(k <= 0){
			break;
		}
		int ru = fr(x.first), rv = fr(x.second);
		if(ru == rv){
			continue;
		}
		answer.emplace_back(x.first, x.second, 0);
		k--;
		cnt--;
		p[ru] = rv;
	}
	noSol(k != 0);
	for(auto x: road[1]){
		int ru = fr(x.first), rv = fr(x.second);
		if(ru == rv){
			continue;
		}
		answer.emplace_back(x.first, x.second, 1);
		cnt--;
		p[ru] = rv;
	}
	noSol(cnt > 1);
	for(auto x: answer){
		cout << x.u << " " << x.v << " " << x.w << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
