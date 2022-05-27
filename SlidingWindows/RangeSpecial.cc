/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Range Special
 * ALGO		: Sliding Windows
 * DATE		: 25 May 2022
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
ll a[MxN], n, p, q;
deque<pair<ll, ll>> minn, maxx;

inline ll slide(ll limit){
	ll cnt = 0ll, rr = 0ll;
	while(!minn.empty()){
		minn.pop_front();
	}
	while(!maxx.empty()){
		maxx.pop_front();
	}
	for(ll i=1; i<=n; ++i){
		while(!minn.empty() && minn.back().second > a[i]){
			minn.pop_back();
		}
		while(!maxx.empty() && maxx.back().second < a[i]){
			maxx.pop_back();
		}
		maxx.emplace_back(i, a[i]); minn.emplace_back(i, a[i]);
		while(!minn.empty() && !maxx.empty() && maxx.front().second - minn.front().second > limit){
			// slide most left first
			if(maxx.front().first < minn.front().first){
				rr = maxx.front().first;
				maxx.pop_front();
			}
			else{
				rr = minn.front().first;
				minn.pop_front();
			}
		}
		cnt += (i - rr); // in-range
	}
	return cnt;
}

inline void solution(){
	cin >> n >> p >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}	
	cout << slide(q) - slide(p - 1);
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
