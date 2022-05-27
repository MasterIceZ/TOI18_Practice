/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Ice Wave
 * ALGO		: Dynamic Programming
 * DATE		: 26 May 2022
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

const int MxN = 2e4 + 10;
const ll MOD = 1e9 + 7;
ll dp[2][MxN * 2];
const int off = 20000;

inline void solution(){
	int n;
	cin >> n;
	memset(dp, 0, sizeof dp);
	dp[0][off] = 1ll;
	ll answer = 0ll;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		memset(dp[i % 2], 0, sizeof dp[i % 2]);
		for(int state=0; state<=2 * off; ++state){
			if(state - x >= 0){
				dp[i % 2][state - x] = (dp[i % 2][state - x] + dp[(i + 1) % 2][state]) % MOD;
			}
			if(state + x <= 2 * off){
				dp[i % 2][state + x] = (dp[i % 2][state + x] + dp[(i + 1) % 2][state]) % MOD;
			}
		}
		answer = (answer + dp[i % 2][off]) % MOD;
		dp[i % 2][off] = (dp[i % 2][off] + 1ll) % MOD;
	}
	cout << answer;
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
