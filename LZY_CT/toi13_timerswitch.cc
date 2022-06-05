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

const int MxN = 5000050;
int pi[MxN];

inline void solution(){
	int n;
	string p, t;
	cin >> n >> p;
	t = " " + p + p; p = " " + p;
	for(int i=2, j=0; i<=n; ++i){
		while(j > 0 && p[j + 1] != p[i]){
			j = pi[j];
		}
		j += (p[i] == p[j + 1]);
		pi[i] = j;
	}
	for(int i=2, j=0; i<=2*n; ++i){
		while(j > 0 && p[j + 1] != t[i]){
			j = pi[j];
		}
		j += (p[j + 1] == t[i]);
		if(j == n){
			cout << i - n;
			return ;
		}
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
