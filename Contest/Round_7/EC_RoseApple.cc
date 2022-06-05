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

map<int, int> mp[3];
map<pair<int, int>, bool> in_used;

inline void solution(){
	int n, k, idx = -1;
	cin >> n >> k;
	for(int i=1, a, b; i<=n; ++i){
		cin >> a >> b;
		if(in_used[make_pair(a, b)]){
			continue;
		}
		in_used[make_pair(a, b)] = true;
		mp[0][a]++, mp[1][b]++, mp[2][a - b]++;
		if(mp[0][a] >= k || mp[1][b] >=k || mp[2][a - b] >= k){
			if(idx != -1){
				continue;
			}
			idx = i;
		}
	}
	cout << idx;
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
