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

const int MxN = 100010;
vector<int> adj[MxN];
bitset<MxN> cutted;
int dp[MxN], p[MxN];

void dfs(int u, int p){
	dp[u] = 1;
	::p[u] = u;
	int maxx = 0, idx = -1;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		if(dp[x] > maxx){
			maxx = dp[x];
			idx = x;
		}
	}
	if(idx == -1){
		return ;
	}
	::p[idx] = u;
	dp[u] = 1 + maxx;
}

int fr(int u){
	return u == p[u]? u: p[u] = fr(p[u]);
}

inline void solution(){
	int u, v, n;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v); adj[v].emplace_back(u);
	}
	dfs(1, 1);
	vector<int> answer;
	for(int i=1; i<=n; ++i){
		int ri = fr(i);
		if(cutted[ri]){
			continue;
		}
		cutted[ri] = true;
		answer.emplace_back(dp[ri]);
	}
	sort(answer.begin(), answer.end(), greater<int> ());
	cout << answer.size() << "\n";
	for(auto x: answer){
		cout << x << "\n";
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
