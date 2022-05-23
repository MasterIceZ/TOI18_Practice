/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Tiles
 * ALGO		: Dynamic Programming
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

const int MxN = 5050;
const int MOD = 1e9 + 7;
char a[3][MxN];
int dp[3][MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=2; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
			if(a[i][j] == '.' || a[i][j] == '#'){
				continue;
			}
			while(1);
		}
	}
	dp[1][0] = dp[2][0] = 1;
	for(int i=1; i<=n; ++i){
		if(a[1][i] == '.' && a[2][i] == '.'){
			dp[1][i] = dp[2][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		}
		else if(a[2][i] == '.'){
			dp[1][i] = 0;
			dp[2][i] = dp[2][i - 1];
		}
		else if(a[1][i] == '.'){
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = 0;
		}
		else{
			dp[1][i] = dp[2][i] = 0;
		}
	}
	cout << (dp[1][n] + dp[2][n]) % MOD;
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
