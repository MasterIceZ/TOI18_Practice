/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Tree
 * ALGO		: Dynamic Programming, Tree
 * DATE		: 11 May 2022
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

const int MxN = 100100;
vector<int> adj[MxN];
ll a[MxN], sum, minn;

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		a[u] += a[x];
	}
	minn = min(minn, abs(sum - 2 * a[u]));	
}

inline void solution(){
	int n, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}	
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sum = accumulate(a + 1, a + n + 1, 0ll);
	minn = 2e18 + 100;
	dfs(1, 0);
	cout << minn;
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
