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

const int MxN = 300030;
int sz[MxN], dp[MxN][255];
string s;

int calc(int l, int r){
	int cnt = 0;
	for(int i='a'; i<='z'; ++i){
		cnt += (dp[r][i] - dp[l - 1][i] > 0);
	}
	return cnt;
}

inline void solution(){
	cin >> s;
	int n = s.size();
	s = " " + s;
	for(int i=1; i<=n; ++i){
		dp[i][s[i]]++;
		for(int j='a'; j<='z'; ++j){
			dp[i][j] += dp[i - 1][j];
		}
	}
	dbg(dp[4]['a']);
	int maxx = 0;
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			int cur = calc(i, j);
			dbg(i, j, cur);
			sz[cur]++;
			maxx = max(cur, maxx);
		}
	}
	cout << maxx << "\n";
	for(int i=1; i<=maxx; ++i){
		cout << sz[i] << "\n";
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
