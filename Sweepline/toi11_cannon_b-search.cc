/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_cannon
 * ALGO		: Binary Search
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
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	while(k--){
		int res = 0, sz = 0;
		for(int i=1, x; i<=m; ++i){
			cin >> x;
			auto idx = lower_bound(a + sz + 1, a + n + 1, x - l);
			auto idx2 = upper_bound(a + sz + 1, a + n + 1, x + l);
			res += (idx2 - idx);
			sz = idx2 - (a + 1);
		}
		cout << res << "\n";
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
