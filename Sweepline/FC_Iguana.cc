/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Iguana
 * ALGO		: Sweepline
 * DATE		: 8 May 2022
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
	ll n, l, r;
	int m, t;
	cin >> n >> m;
	map<ll, ll> mp;
	for(int i=1; i<=m; ++i){
		cin >> l >> r;
		mp[l]++, mp[r + 1]--;
	}
	char w;
	cin >> w;
	if(w == 'R'){
		t = 0;
	}
	else if(w == 'G'){
		t = 1;
	}
	else{
		t = 2;
	}
	mp[1] += 0; // create first point
	mp[n + 1] = 0; // create end point
	ll res = 0, last = 1, sum = 0;
	for(auto x: mp){
		res += ((t - sum + 3) % 3) * (x.first - last);
		sum = (sum + x.second) % 3;
		last = x.first;
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
