/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi16_carte
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

const int MxN = 440;
int n, m, a[MxN];
pair<int, int> dp[MxN][MxN], t;

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i][i] = make_pair(1, 1);
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			dp[l][r] = make_pair(1 + dp[l + 1][r].first, 1);
			for(int k=l; k<r; ++k){
				if(a[l] != a[k + 1]){
					continue;
				}
				t = make_pair(dp[l + 1][k].first + dp[k + 1][r].first, dp[k + 1][r].second + 1);
				t.first += (t.second > m);
				t.second = (t.second > m? 1: t.second);
				dp[l][r] = min(dp[l][r], t);
			}	
		}
	}
	cout << dp[1][n].first;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q >> m;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
