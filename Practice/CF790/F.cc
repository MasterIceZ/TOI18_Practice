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

map<int, int> mp;

inline void solution(){
	mp.clear();
	int n, k;
	cin >> n >> k;
	bool ok = false;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x]++;
		if(mp[x] >= k){
			ok = true;
		}
	}
	if(!ok){
		cout << -1;
		return ;
	}
	int last = 0;
	int l = -1, r = -1, maxx = -1, current_l = -1, current_r = -1;
	for(auto x: mp){
		if(x.second < k){
			current_l = -1;
			current_r = -1;
			continue;
		}
		if(x.first - last != 1){
			current_l = x.first;
			current_r = x.first;
		}
		else if(current_l != -1){
			current_r = x.first;
		}
		else{
			current_l = x.first;
			current_r = x.first;
		}
		last = x.first;
		if(current_r - current_l + 1 > maxx){
			l = current_l;
			r = current_r;
			maxx = current_r - current_l + 1;
		}
		dbg(current_l, current_r, l, r);
	}
	if(maxx != -1){
		cout << l << " " << r;
	}
	else{
		dbg("NOT OK");
		cout << -1;
	}
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
