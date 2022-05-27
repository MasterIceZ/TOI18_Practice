/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Group
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

const int MxN = 100010;
int n, sz;
pair<int, int> a[MxN];
int dp[MxN];

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
		a[i].second = -a[i].second;
	}
	sort(a + 1, a + n + 1);
	sz = 0;
	for(int i=1; i<=n; ++i){
		int idx = upper_bound(dp, dp + sz, a[i].second) - dp;
		dp[idx] = a[i].second;
		sz += (idx == sz);
	}
	cout << sz;
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
