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

inline bool ok(int a){
	int sq = sqrt(a);
	int cnt = 1, cnt_now;
	for(int i=2; i<=sq; ++i){
		cnt_now = 0;
		while(a % i == 0){
			a /= i;
			cnt_now++;	
		}
		cnt = cnt * (1 + cnt_now);
		if(cnt > 5){
			return false;
		}
	}
	if(a != 1){
		cnt = cnt * 2;
	}
	return cnt <= 5;
}

inline void solution(){
	int expected = 70000;
	int i = 0;
	set<int> answer;
	while((int) answer.size() < expected){
		++i;
		if(ok(i)){
			answer.emplace(i);
		}
		dbg(i, answer.size());
	}
	cout << i;
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
