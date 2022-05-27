/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_segitiga operation
 * ALGO		: Dynamic Programming
 * DATE		: 23 May 2022
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

const int MxN = 330;
int n;
string s;
bool dp[MxN][MxN][3];

inline int convert(int a, int b){
	if(a == 0){
		return 2 - b;
	}
	if(a == 1){
		return b == 0? 2: 1;
	}
	return b == 1? 2: 1;
}

inline bool solution(){
	memset(dp, 0, sizeof dp);	
	cin >> n >> s;
	s = " " + s;
	if(s[1] != '0'){
		return false;
	}
	for(int i=1; i<=n; ++i){
		dp[i][i][s[i] - '0'] = true;
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			for(int k=l; k<r; ++k){
				for(int i=0; i<=2; ++i){
					for(int j=0; j<=2; ++j){
						if(dp[l][k][i] && dp[k + 1][r][j]){
							dp[l][r][convert(i, j)] = true;
						}
					}
				}
			}
		}	
	}
	return dp[1][n][0];
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 20;
//	cin >> q;
	while(q--){
		cout << (solution()? "yes": "no");
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
