/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Wildfire
 * ALGO		: Dynamic Programming
 * DATE		: 28 May 2022
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

const int MOD = 1e9 + 7;
const int MxN  = 27;
int c[MxN][MxN], dp[MxN][MxN];
bitset<MxN> used;

inline void solution(){
	int n, k;
	cin >> n >> k;
	cout << dp[n][k];
	return ;
}

inline int C(int n, int r){
	if(c[n][r] != 0){
		return c[n][r];
	}
	if(n == 0 || n == 1 || n == r || r == 0){
		return 1;
	}
	return (C(n - 1, r - 1) + C(n - 1, r)) % MOD;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	for(int n=1; n<=25; ++n){
		for(int k=1; k<=n; ++k){
			used = 0;
			int i = 1;
			while(!used[n - i] && !used[i] && i <= n){
				dbg(n, k, i);
				int now = C(n - i, i);
				if(n - i == i){
					now = now >> 1;
				}
				dp[n][k] = (dp[n][k] + now) % MOD;
				used[i] = true;
				used[n - i] = true;
				++i;
			}
		}
	}
	for(int i=1; i<=4; ++i){
		for(int j=1; j<=i; ++j){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
