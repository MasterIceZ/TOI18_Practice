/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Stone Age Problem
 * ALGO		: Map
 * DATE		: 14 May 2022
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

const int MxN = 250050;
ll a[MxN], v;

inline void solution(){
	int n, q, t, idx;
	cin >> n >> q;
	map<ll, ll> mp;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		mp[i] = a[i];
	}
	ll sum = accumulate(a + 1, a + n + 1, 0ll), last_all = 0;
	while(q--){
		cin >> t;
		if(t == 1){
			cin >> idx >> v;
			if(mp.find(idx) != mp.end()){
				sum = sum - mp[idx] + v;
			}
			else{
				sum = sum - last_all + v;
			}
			mp[idx] = v;
		}
		else{
			cin >> v;
			sum = (ll)(n) * v;
			last_all = v;
			mp.clear();
		}
		cout << sum << "\n";
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
