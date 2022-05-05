/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_food
 * ALGO		: Brute Force
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

int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
bool ok[10];

inline void solution(){
	int n, k;
	cin >> n >> k;
	memset(ok, true, sizeof ok);
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		ok[x] = false;
	}
	do{
		if(!ok[a[0]]){
			continue;
		}
		for(int i=0; i<n; ++i){
			cout << a[i] << " ";
		}
		cout << "\n";
	}while(next_permutation(a, a + n));
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
