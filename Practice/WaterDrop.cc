/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: codecube_223
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

const int MxN = 7070;
char s[MxN];
int dp[2][MxN], cnt[MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> (s + 1);
		memset(dp[i % 2], 0, sizeof dp[i % 2]);
		for(int j=1; j<=m; ++j){
			if(s[j] == '0'){
				continue;
			}
			dp[i % 2][j] = 1 + min({dp[(i + 1) % 2][j], dp[i % 2][j - 1], dp[(i + 1) % 2][j - 1]});
			cnt[dp[i % 2][j]]++;
		}
	}
	for(int i=min(n, m); i>0; --i){
		cnt[i] = cnt[i] + cnt[i + 1];
	}
	for(int i=1; i<=min(n, m); ++i){
		cout << cnt[i] << "\n";
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
