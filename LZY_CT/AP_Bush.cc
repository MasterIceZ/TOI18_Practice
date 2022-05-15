/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Bush
 * ALGO		: Search by Elimination
 * DATE		: 14 May 2022
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

const int MxN = 1010;
ll a[MxN], n, k;

inline bool ok(ll x){
	ll cnt = (x + 1ll) * (x + 1ll) * n;
	for(int i=2; i<=n; ++i){
		if(a[i] == a[i - 1]){
			cnt -= (x + 1ll) * (x + 1ll);
			continue;
		}
		ll d = a[i] - a[i - 1] - 1ll;
		if(d % 2){
			d >>= 1;
			if(d < x){
				d = x - d;
				cnt -= d * d;
			}
		}
		else{
			d >>= 1;
			if(d < x){
				d = x - d;
				cnt -= d * (d + 1ll);
			}
		}
	}
	return cnt < k;
}

inline void solution(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = 0, r = 1e9 + 100;
	while(l < r){
		ll mid = (l + r) >> 1;
		if(ok(mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << r;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
