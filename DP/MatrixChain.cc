/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Matrix Chain
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

const int MxN = 22;
int dp[MxN][MxN], row[MxN], col[MxN], from[MxN][MxN];

void dfs(int l, int r){
	if(l == r){
		cout << "A" << l;
		return ;
	}
	cout << "(";
	dfs(l, from[l][r]);
	cout << " x ";
	dfs(from[l][r] + 1, r);
	cout << ")";
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> row[i] >> col[i];
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			dp[l][r] = 1e9 + 100;
			for(int k=l; k<r; ++k){
				int now = dp[l][k] + dp[k + 1][r] + row[l] * col[k] * col[r];
				if(now < dp[l][r]){
					dp[l][r] = now;
					from[l][r] = k;
				}
			}
		}
	}
	cout << dp[1][n] << "\n";
	dfs(1, n);
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
