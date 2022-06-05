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

int n, k, a[33];
set<vector<vector<int>>> st;

void rec(vector<int> v){
	if(v.size() == n){
		int bit = 0;
		vector<vector<int>> now(k);
		for(auto x: v){
			bit |= (1 << x);
			v[x].emplace_back();
		}
		if(bit == (1 << k) - 1){
			st.emplace(v);
		}
		return ;
	}
	v.emplace_back(-1);
	for(int i=0; i<k; ++i){
		v.back() = i;
		rec(v);
	}
}

inline void solution(){
	for(n=1; n<=4; ++n){
		for(k=1; k<=n; ++k){
			st.clear();
			rec({});
			cout << st.size() << " ";
		}
		cout << "\n";
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
