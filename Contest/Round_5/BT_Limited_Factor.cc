/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BT_Limited Factor
 * ALGO		: Math
 * DATE		: 27 May 2022
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

const int MxN = 300000 + 30;
int a[MxN];

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
	vector<int> arr;
	int it = 0, x, t;
	while((int) arr.size() < 1000){
		++it;
		if(ok(it)){
			arr.emplace_back(it);
		}
	}	
	cin >> t;
	while(t--){
		cin >> x;
		if(x > 1000){
			return ;
		}
		cout << arr[x - 1] << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
