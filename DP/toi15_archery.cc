/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_archery
 * ALGO		: Dynamic Programming
 * DATE		: 24 May 2022
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

const int MxN = 500050;
pair<ll, ll> a[MxN], qs[MxN];

inline void solution(){
	ll n, minn = 1e18;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].second;
		minn = min(minn, a[i].second);
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i].first;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i){
		qs[i] = make_pair(qs[i - 1].first + a[i].first, qs[i - 1].second + a[i].second);
	}
	ll answer = 1e18 + 20, idx = -1;
	for(ll i=1; i<=n; ++i){
		if(a[i].first > minn){
			break;
		}
		ll l = qs[i - 1].first + qs[i - 1].second - (i - 1ll) * a[i].first;
		ll r = qs[n].first - qs[i].first - (n - i) * a[i].first;
		ll sum = l + r;
		if(sum < answer){
			answer = sum;
			idx = a[i].first;
		}
	}
	cout << idx << " " << answer;
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
