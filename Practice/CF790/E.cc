/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 150050;
ll v[MxN], dp[MxN];

inline void solution(){
	int n, q;
	cin >> n >> q;
	ll x;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	sort(v + 1, v + n + 1, greater<ll> ());
	for(int i=1; i<=n; ++i){
		dp[i] = dp[i - 1] + v[i];
	}
	dbg(to_string(dp, 1, n));
	while(q--){
		cin >> x;
		int idx = lower_bound(dp + 1, dp + n + 1, x) - (dp);
		if(idx <= n){
			cout << idx << "\n";
		}
		else{
			cout << -1 << "\n";
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
