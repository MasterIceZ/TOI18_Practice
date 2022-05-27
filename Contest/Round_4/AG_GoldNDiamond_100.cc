/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_GoldnDiamond
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

const int MxN = 770;
int n, m;
ll a[MxN][MxN];
ll ul[MxN][MxN], ur[MxN][MxN], dl[MxN][MxN], dr[MxN][MxN], qsr[MxN][MxN], qsc[MxN][MxN];

inline void setup(){
	memset(ul, 0x3f, sizeof ul);
	memset(ur, 0x3f, sizeof ur);
	memset(dl, 0x3f, sizeof dl);
	memset(dr, 0x3f, sizeof dr);
}

inline void solution(){
	setup();
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			qsr[i][j] = qsr[i][j - 1] + a[i][j];
			qsc[i][j] = qsc[i - 1][j] + a[i][j];
		}
	}
	dr[0][1] = 0, dr[1][0] = 0;
	dl[0][m] = 0, dr[1][m + 1] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dr[i][j] = a[i][j] + min(dr[i - 1][j], dr[i][j - 1]);
		}
		for(int j=m; j>=1; --j){
			dl[i][j] = a[i][j] + min(dl[i - 1][j], dl[i][j + 1]);
		}
	}
	ur[0][n] = 0, ur[n + 1][1] = 0;
	ul[n][m + 1] = 0, dl[n + 1][m] = 0;
	for(int i=n; i>=1; --i){
		for(int j=1; j<=m; ++j){
			ur[i][j] = a[i][j] + min(ur[i + 1][j], ur[i][j - 1]);
		}
		for(int j=m; j>=1; --j){
			ul[i][j] = a[i][j] + min(ul[i + 1][j], ul[i][j + 1]);
		}
	}
	ll answer = 1e18 + 20;
	for(int i=1; i<=n; ++i){
		ll slide = 1e18 + 100ll;
		for(int j=1; j<=m; ++j){
			slide = min(slide, dr[i][j] + ur[i][j] - 2 * a[i][j] - qsr[i][j - 1]);
			answer = min(answer, slide + dl[i][j] + ul[i][j] - 2 * a[i][j] + qsr[i][j]);
		}
	}
	for(int j=1; j<=m; ++j){
		ll slide = 1e18 + 100ll;
		for(int i=1; i<=n; ++i){
			slide = min(slide, dr[i][j] + dl[i][j] - 2 * a[i][j] - qsc[i - 1][j]);
			answer = min(answer, slide + ul[i][j] + ur[i][j] - 2 * a[i][j] + qsc[i][j]);
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
