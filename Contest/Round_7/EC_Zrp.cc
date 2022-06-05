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

const int MxN = 200020;
ll s[MxN];

inline void solution(){
	int opr, n, sz = 1, last = 0;
	ll sum = 0ll, b, a;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> a >> b;
			for(int it=1; it<=a; ++it){
				s[it] += b;
			}
			sum += (b * (ll) a);
		}
		else if(opr == 2){
			cin >> a;
			sum += a;
			s[++sz] = a;
		}
		else{
			sum -= s[sz];
			s[sz--] = 0;
		}
		cout << sum << " " << sz << "\n";
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
