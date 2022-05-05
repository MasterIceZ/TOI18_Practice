/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi8_electricity
 * ALGO		: Sliding Windows
 * DATE		: 5 May 2022
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

const int MxN = 500050;
int dp[MxN], a[MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	deque<pair<int, int>> dq;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	dq.emplace_back(a[1], 1);
	for(int i=1; i<=n; ++i){
		while(!dq.empty() && dq.front().second < i - k){
			dq.pop_front();
		}
		dp[i] = dq.front().first + a[i];
		while(!dq.empty() && dq.back().first >= dp[i]){
			dq.pop_back();
		}
		dq.emplace_back(dp[i], i);
	}
	cout << dp[n];
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
