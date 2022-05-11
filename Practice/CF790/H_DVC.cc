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
ll cnt = 0, a[MxN], b[MxN];

inline void merge(ll l, ll r){
	ll mid = (l + r) >> 1;
	ll i = l, j = mid + 1, k = l;
	while(i<=mid && j<=r){
		if(a[i] < a[j]){
			b[k++] = a[i++];
		}
		else{
			cnt += (mid - i + 1ll);
			b[k++] = a[j++];
		}
	}
	while(i<=mid){
		b[k++] = a[i++];
	}
	while(j<=r){
		b[k++] = b[j++];
	}
	for(int i=l; i<=r; ++i){
		a[i] = b[i];
	}
}

void merge_sort(ll l, ll r){
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, r);
}

inline void solution(){
	cnt = 0ll;
	ll n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	merge_sort(1ll, n);
	cout << cnt;
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
