/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi17_noodle
 * ALGO		: Search by Elimination, Heap
 * DATE		: 31 May 2022
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

const int MxN = 100010;
ll a[MxN];
int n, m, k;
priority_queue<ll, vector<ll>, greater<ll>> pq;

inline bool ok(ll x){
	while(!pq.empty()){
		pq.pop();
	}
	ll sum = 0ll;
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		sum += a[i];
		pq.emplace(a[i]);
		if((int) pq.size() >= k){
			if(sum >= x){
				sum = 0;
				cnt++;
				while(!pq.empty()){
					pq.pop();
				}
			}
			else{
				sum -= pq.top();
				pq.pop();
			}
		}
	}
	return cnt >= m;
}

inline void solution(){
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 1, r = 1e18 + 10ll;
	while(l < r){
		ll mid = (l + r + 1ll) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1ll;
		}
	}
	cout << l;
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
