/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Tension 5
 * ALGO		: Dynamic Programming, Binary Lifting
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

const int MxN = 262144 + 10;
int a[MxN], dp[2][MxN]; // dp[i][j] stores next index which use to merge!

inline void solution(){
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int now, last, MxS = 40 + log2(n), answer = 0;
	for(int state=0; state<=MxS; ++state){
		now = state % 2, last = 1 - now;
		for(int i=1; i<=n; ++i){
			if(a[i] == state){
				dp[now][i] = i + 1; // next to merge
			}
			else{
				dp[now][i] = dp[last][dp[last][i]]; // check next to merge with binary lifting
			}
			if(dp[now][i] > 0){
				answer = state;
			}
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
