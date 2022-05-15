/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi14_blockchain
 * ALGO		: Brute Force
 * DATE		: 15 May 2022
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

using pii = pair<int, int>;

inline void solution(){
	map<vector<pii>, int> mp;
	vector<pii> g;
	int n, q, m, u, v;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> m;
		g.clear();
		for(int j=2; j<=m; ++j){
			cin >> u >> v;
			g.emplace_back(min(u, v), max(u, v));
		}
		sort(g.begin(), g.end());
		mp[g]++;
	}
	while(q--){
		cin >> m;
		g.clear();
		for(int i=2; i<=m; ++i){
			cin >> u >> v;
			g.emplace_back(min(u, v), max(u, v));
		}
		sort(g.begin(), g.end());
		cout << mp[g] << "\n";
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
