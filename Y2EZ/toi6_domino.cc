/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_domino
 * ALGO		: Brute Force
 * DATE		: 4 May 2022
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

int n;
string v[22];

void rec(int state, int cnt){
	if(state == n){
		for(int i=0; i<cnt; ++i){
			cout << v[i] << "\n";
		}
		cout << "E\n";
		return ;
	}
	if(state + 1 <= n){
		v[cnt] = "--";
		rec(state + 1, cnt + 1);
		v[cnt] = "";
	}
	if(state + 2 <= n){
		v[cnt] = "||";
		rec(state + 2, cnt + 1);
		v[cnt] = "";
	}
}

inline void solution(){
	cin >> n;
	rec(0, 0);
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
