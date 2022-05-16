/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tension 4
 * ALGO		: Math
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

inline ll s(ll x){
	ll l = 1ll, r = x;
	while(l <= r){
		ll mid = (l + r) / 2ll;
		if(mid * mid == x){
			return mid;
		}
		if(mid <= x / mid){
			l = mid + 1ll;
		}
		else{
			r = mid - 1ll;
		}
	}
	return l - 1ll;
}

inline void solution(){
	ll n, q, l, r;
	cin >> n >> q;
	while(q--){
		cin >> l >> r;
		cout << s(r) + s(r / 2ll) - s(l - 1ll) - s((l - 1ll) / 2ll) << "\n"; 
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
