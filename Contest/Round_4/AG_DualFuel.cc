/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Dual Fuel
 * ALGO		: Sliding Windows
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

const int MxN = 2000020;
ll a[MxN][2];
// min deq
deque<pair<int, ll>> dq;

inline void solution(){
	int n, v;
	cin >> n >> v;
	for(int i=0; i<n; ++i){
		cin >> a[i][0];
	}
	for(int i=0; i<n; ++i){
		cin >> a[i][1];
	}
	ll answer = 0ll;
	for(int state=0; state<=1; ++state){
		while(!dq.empty()){
			dq.pop_front();
		}
		dq.emplace_back(0, a[0][state]);
		for(int i=1; i<=n; ++i){
			// cannot reach
			while(!dq.empty() && v + dq.front().first < i){
				dq.pop_front();
			}
			// fill more fuel
			answer = answer + dq.front().second;
			while(!dq.empty() && dq.back().second > a[i][state]){
				dq.pop_back();
			}
			dq.emplace_back(i, a[i][state]);
		}
	}
	cout << answer;
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
