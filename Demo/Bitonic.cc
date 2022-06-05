/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Bitonic
 * ALGO		: Brute Force
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

const int MxN = 110;
int v[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	int idx, maxx = *max_element(v + 1, v + n + 1);
	for(int i=1; i<=n; ++i){
		if(v[i] == maxx){
			idx = i;
		}
	}
	for(int i=idx-1; i>=1; --i){
		if(v[i + 1] <= v[i]){
			cout << "No";
			return ;
		}
	}
	for(int i=idx+1; i<=n; ++i){
		if(v[i - 1] <= v[i]){
			cout << "No";
			return ;
		}
	}
	cout << "Yes";
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
