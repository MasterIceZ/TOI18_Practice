/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Pager
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

const int MxN = 220;
int n;
vector<int> compress;
ll a[MxN], b[MxN], c[MxN], cost[2 * MxN][2 * MxN], dp[2 * MxN][2 * MxN];

ll divide(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l + 1 == r){
		return dp[l][r] = cost[l][r];
	}
	ll res = -1e18 - 20;
	for(int k=l+1; k<r; ++k){
		res = max(res, divide(l, k) + divide(k, r));
	}
	return dp[l][r] = res + cost[l][r];
}

inline void solution(){
	memset(cost, 0, sizeof cost);
	memset(dp, -1, sizeof dp);
	compress.clear();
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i] >> c[i];
		compress.emplace_back(a[i]);
		compress.emplace_back(b[i]);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(compress.begin(), compress.end(), a[i]) - compress.begin();
		b[i] = upper_bound(compress.begin(), compress.end(), b[i]) - compress.begin();
		cost[a[i]][b[i]] = c[i];
	}
	n = compress.size();
	cout << divide(1, n);
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
