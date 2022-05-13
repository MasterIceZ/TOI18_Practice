/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Boba Inversion
 * ALGO		: Dynamic Programming
 * DATE		: 12 May 2022
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

const int MxN = 5050;
int a[MxN], dp[MxN][MxN], tick[MxN][MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			tick[i][j] = (a[i] > a[j]);
		}
	}
	memcpy(dp, tick, sizeof tick);
	for(int i=n; i>=1; --i){
		for(int j=1; j<=n; ++j){
			dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
		}
	}
	int q, l, r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << dp[l][r] << "\n";
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
