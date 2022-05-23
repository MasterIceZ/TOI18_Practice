/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jump
 * ALGO		: Search by elimination
 * DATE		: 23 May 2022
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

const int MxN = 1000010;
int n, k, p, a[MxN], b[MxN];

inline bool ok(int x){
	int cnt = 0;
	for(int i=1; i<=n; ){
		if(b[x] < a[i]){
			cnt++;
			i += p;
		}
		else{
			i += 1;
		}
	}
	return cnt <= k;
}

inline void solution(){
	cin >> n >> k >> p;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memcpy(b, a, sizeof b);
	int l = 1, r = n;
	sort(b + 1, b + n + 1);
	while(l < r){
		int mid = (l + r) >> 1;
		if(ok(mid)){
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
