/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Silver
 * ALGO		: Dynamic Programming, Tree, Disjoint Set Union, Sack
 * DATE		: 26 May 2022
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

const int MxN = 1010;
int p[MxN], sz[MxN], dp[MxN];
vector<int> adj[MxN];

int fr(int u){
	return u == p[u]? u: fr(p[u]);
}

void dfs(int u){
	for(auto x: adj[u]){
		dfs(x);
		dp[u] = max(dp[x], dp[u]);
	}
	dp[u] = dp[u] + 1;
}

inline void solution(){
	int n, m, q, o, u, v, x;
	cin >> n >> m >> q;
	if(m != 0 || n > 1000 || q > 1000){
		return ;
	}
	for(int i=1; i<=n; ++i){
		sz[i] = 1;
		p[i] = i;
	}
	while(q--){
		cin >> o;
		if(o == 2){
			cin >> u >> v;
			int ru = fr(u), rv = fr(v);
			dbg(ru, rv, sz[ru], sz[rv]);
			if(sz[ru] > sz[rv]){
				p[rv] = ru;
				sz[ru] = sz[ru] + sz[rv];
				adj[ru].emplace_back(rv);
			}
			else{
				p[ru] = rv;
				sz[rv] = sz[ru] + sz[rv];
				adj[rv].emplace_back(ru);
			}
		}
		else{
			cin >> x;
			x = fr(x);
			memset(dp, 0, sizeof dp);
			dfs(x);
			dbg(to_string(dp, 1, n));
			int mst = 0, ndmst = 0;
			for(int i=1; i<=n; ++i){
				if(i == x){
					continue;
				}
				if(mst < dp[i]){
					ndmst = mst;
					mst = dp[i];
				}
				else if(ndmst < dp[i]){
					ndmst = dp[i];
				}
			}
			cout << ndmst + mst << "\n";
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
