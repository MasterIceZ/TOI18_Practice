/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_tree
 * ALGO		: Brute Force
 * DATE		: 4 May 2022
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

inline void solution(){
	int n;
	cin >> n;
	vector<pair<int, int>> a, b;
	for(int i=1, x, y; i<n; ++i){
		cin >> x >> y;
		a.emplace_back(min(x, y), max(x, y));
	}
	for(int i=1, x, y; i<n; ++i){
		cin >> x >> y;
		b.emplace_back(min(x, y), max(x, y));
	}
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	cout << (a == b ? "Y": "N");
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 5;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
