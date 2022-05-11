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

const int MxN = 220;
int n, m;
ll a[MxN][MxN], dp[2][MxN];

inline ll calc(int x, int y){
	ll res = -3ll * a[x][y];
	for(int xx=x, yy=y; xx>=1 && yy>=1; --xx, --yy){
		res += a[xx][yy];
	}
	for(int xx=x, yy=y; xx<=n && yy<=m; ++xx, ++yy){
		res += a[xx][yy];
	}
	for(int xx=x, yy=y; xx<=n && yy>=1; ++xx, --yy){
		res += a[xx][yy];
	}
	for(int xx=x, yy=y; xx>=1 && yy<=m; --xx, ++yy){
		res += a[xx][yy];
	}
	return res;
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			answer = max(answer, calc(i, j));
		}
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
