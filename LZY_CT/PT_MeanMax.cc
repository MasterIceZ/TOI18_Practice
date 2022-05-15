/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Mean Max
 * ALGO		: Search By Elimination, Dynamic Programming
 * DATE		: 13 May 2022
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

const int MxN = 300030;
const double os = 1e-6;
int n, k;
double a[MxN], qs[MxN], slide[MxN];

inline bool ok(double x){
	for(int i=1; i<=n; ++i){
		qs[i] = qs[i - 1] + a[i] - x;
		slide[i] = min(slide[i - 1], qs[i]);
		if(i >= k && qs[i] - slide[i - k] >= 0){
			return true;
		}
	}
	return false;
}

inline void solution(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	double l = 0, r = 1e6 + 1000;
	while(r - l > os){
		double mid = (l + r + os) / 2;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - os;
		}
	}
	cout << fixed << setprecision(1) << l;
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
