/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Colorful Garden
 * ALGO		: Dynamic Programming
 * DATE		: 22 Mar 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
// @==== Libary ====@ //

// @================@ //

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

const int MxN = 1e3 + 20;
const int MOD = 1e6 + 3;
vector<int> adj[MxN], b[MxN];
ll dp[MxN][1 << 10];
int a[MxN];

inline void solution(){
	int n, m, c;
	cin >> n >> m >> c;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		dp[i][1 << a[i]]++;
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<(1 << c); ++i){
		b[__builtin_popcount(i)].push_back(i);
	}
	for(int i=2; i<=c; ++i){
		for(auto state: b[i]){
			for(int u=0; u<n; ++u){
				if(!(state & (1 << a[u]))){
					continue;
				}
				for(auto v: adj[u]){
					dp[u][state] = (dp[u][state] + dp[v][state ^ (1 << a[u])]) % MOD; 
				}
			}
		}
	}
	ll res = 0ll;
	for(int i=0; i<n; ++i){
		res = (res + dp[i][(1 << c) - 1]) % MOD;
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
