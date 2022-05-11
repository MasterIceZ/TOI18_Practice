/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_bomb
 * ALGO		: Math
 * DATE		: 6 May 2022
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

inline bool compare_bomb(const pair<int, int> A, const pair<int, int> B){
	if(A.first != B.first){
		return A.first > B.first;
	}
	return A.second < B.second;
}

inline bool compare_answer(const pair<int, int> A, const pair<int, int> B){
	if(A.first != B.first){
		return A.first < B.first;
	}
	return A.second > B.second;
}

const int MxN = 1000010;
pair<int, int> a[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1, compare_bomb);
	int now_x = a[1].first, now_y = a[1].second;
	vector<pair<int, int>> v;
	v.emplace_back(a[1]);
	for(int i=2; i<=n; ++i){
		if(a[i].second >= now_y || a[i].first == now_x){
			now_y = a[i].second;
			v.emplace_back(a[i]);
		}
	}
	sort(v.begin(), v.end(), compare_answer);
	for(auto x: v){
		cout << x.first << " " << x.second << "\n";
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
