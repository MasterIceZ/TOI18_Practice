/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: explore
 * ALGO		: Dynamic Programming
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

const int MxN = 500050;
vector<int> adj[MxN];
bitset<MxN> can, dp;

inline void solution(){
	int res = 0, n, m, k, u, v, x;
	cin >> n >> m >> k;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	can.set();
	for(int i=1; i<=k; ++i){
		cin >> x;
		can[x] = false;
	}
	dp[1] = true;
	for(int i=1; i<=n; ++i){
		if(!dp[i]){
			continue;
		}
		res = i;
		if(can[i]){
			dp[i + 1] = true;
		}
		for(auto x: adj[i]){
			dp[x] = true;
		}
	}
	if(res == n){
		cout << 1;
	}
	else{
		cout << "0 " << res;
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
