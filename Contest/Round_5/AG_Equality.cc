/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Equality
 * ALGO		: Search by Elimination
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

const int MxN = 1e6 + 10;
int n, p, k, a[MxN], b[MxN];

inline bool ok(int x){
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		if(a[i] > x){
			i += p;
			cnt++;
		}
	}
	return cnt <= k;
}

inline void solution(){
	cin >> n >> k >> p;
	p = p - 1;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memcpy(b, a, sizeof a);
	sort(b + 1, b + n + 1);
	int mid, l = 1, r = n;
	while(l < r){
		mid = (l + r) >> 1;
		if(ok(b[mid])){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << b[l];
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
