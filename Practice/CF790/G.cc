/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 4040;
vector<int> adj[MxN];
int dp[MxN][2], cnt = 0;

void dfs(int u){
	for(auto x: adj[u]){
		dfs(x);
		dp[u][1] += dp[x][1];
		dp[u][0] += dp[x][0];
	}
	cnt += (dp[u][0] == dp[u][1]);
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=2, r; i<=n; ++i){
		cin >> r;
		adj[r].emplace_back(i);
	}
	string s;
	cin >> s;
	s = " " + s;
	for(int i=1; i<=n; ++i){
		dp[i][s[i] == 'W']++;
	}
	cnt = 0;
	dfs(1);
	cout << cnt;
	memset(dp, 0, sizeof dp);
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
