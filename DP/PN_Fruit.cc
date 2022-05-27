/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Fruit
 * ALGO		: Dynamic Programming
 * DATE		: 24 May 2022
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

const int MxN = 100010;
int n, sz, idx;
ll qs[MxN], dp[MxN];

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] += qs[i - 1];
	}
	dbg(to_string(qs, 1, n));
	sz = 0;
	memset(dp, 0, sizeof dp);
	for(int i=1; i<=n; ++i){
		if(qs[i] <= 0ll){
			continue;
		}
		idx = lower_bound(dp, dp + sz, qs[i]) - dp;
		dp[idx] = qs[i];
		if(idx == sz){
			dbg(qs[i]);
			sz++;
		}
	}
	cout << idx + 1;
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
