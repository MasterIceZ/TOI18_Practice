/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Pedigree
 * ALGO		: Divide and Conquer
 * DATE		: 21 May 2022
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
ll w;
int k, a[MxN];
bool ok;

ll rec(ll w, int k){
	ll p = 2 * w + 1 - a[k];
	if(p <= 1){
		ok = false;
		return -1e9-10;
	}
	if(k == 1){
		return p;
	}
	return rec(p >> 1, k - 1) + rec(p - (p >> 1), k - 1);
}

inline void solution(){
	ok = true;
	cin >> k >> w;
	for(int i=1; i<k; ++i){
		cin >> a[i];
	}
	ll res = rec(w, k - 1);
	dbg(res);
	cout << (ok? res: -1);
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
