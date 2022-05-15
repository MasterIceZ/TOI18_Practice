/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_keys
 * ALGO		: Dynamic Programming
 * DATE		: 14 May 2022
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

const int MxN = 1010;
bitset<MxN> dp[MxN];

inline void solution(){
	string a, b, c;
	cin >> a >> b;
	int q, n = a.size(), m = b.size();
	a = " " + a, b = " " + b;
	cin >> q;
	while(q--){
		memset(dp, 0, sizeof dp);
		cin >> c;
		c = " " + c;
		dp[0][0] = true;
		for(int i=0; i<=n; ++i){
			for(int j=0; j<=m; ++j){
				if(i != 0 && dp[i - 1][j] && a[i] == c[i + j]){
					dp[i][j] = true;
				}
				if(j != 0 && dp[i][j - 1] && b[j] == c[i + j]){
					dp[i][j] = true;
				}
			}
		}
		cout << (dp[n][m] ? "Yes": "No") << "\n";
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
