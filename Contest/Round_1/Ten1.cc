/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tension 1
 * ALGO		: Dynamic Programming
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

const int MxN = 1000010;
ll qs[MxN], a[MxN], dp[MxN], m;

inline void solution(){
	int q, n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		qs[i] = qs[i - 1] + a[i];
	}
	cin >> q;
	while(q--){
		cin >> m;
		memcpy(dp, qs, sizeof qs);
		for(int i=k+1; i<=n; ++i){
			ll use_ult = m + dp[i - k] + (qs[i] - qs[i - k]) / 2ll;
			ll not_use = dp[i - 1] + a[i];
			dp[i] = min(use_ult, not_use);
		}
		cout << dp[n] << "\n";
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
