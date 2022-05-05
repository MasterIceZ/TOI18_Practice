/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Magnet
 * ALGO		: Sweepline
 * DATE		: 5 May 2022
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
	ll x, n, l, r;
	int m, q;
	cin >> n >> m >> q;
	vector<ll> line;
	for(int i=1; i<=m; ++i){
		cin >> l >> r;
		line.emplace_back(l);
		line.emplace_back(l + r);
	}
	sort(line.begin(), line.end());
	vector<ll> answer = {1ll};
	for(int i=0; i<(int)line.size(); ++i){
		if(line[i] == line[i + 1]){
			i++;
			continue;
		}
		answer.emplace_back(line[i]);
	}
	answer.emplace_back(1 + n);
	while(q--){
		cin >> x;
		auto it = upper_bound(answer.begin(), answer.end(), x);
		auto it2 = it - 1;
		cout << *it - *it2 << "\n";
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
