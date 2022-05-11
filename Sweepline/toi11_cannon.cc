/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_cannon
 * ALGO		: Sweepline?
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

const int MxN = 1000010;
int a[MxN];

inline void solution(){
	int n, m, q, l;
	cin >> n >> m >> q >> l;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	while(q--){
		int cnt = 0, pt = 1;
		for(int i=1, x; i<=m; ++i){
			cin >> x;
			if(pt > n){
				continue;
			}
			while(pt <= n && a[pt] < x - l){
				pt++;
			}
			if(pt > n){
				continue;
			}
			while(pt <= n && a[pt] <= x + l){
				pt++, cnt++;
			}
		}
		cout << cnt << "\n";
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
