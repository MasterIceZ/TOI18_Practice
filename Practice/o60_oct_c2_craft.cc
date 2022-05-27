/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Craft
 * ALGO		: Divide and Conquer
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

const int MxN = 22;
ll a[MxN];
bool ok = true;

ll rec(int l, ll v){
	ll p = ((v << 1) | 1) - a[l];
	if(p <= 1){
		ok = false;
		return -1e9 - 100;
	}	
	if(l == 1){
		return p;
	}
	return rec(l - 1, p >> 1) + rec(l - 1, p - (p >> 1));
}

inline void solution(){
	int n;
	ll w;
	cin >> n >> w;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll res = rec(n - 1, w);
	cout << (ok? res: -1);
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
