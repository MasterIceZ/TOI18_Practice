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

vector<int> v;
int a[33];

inline void solution(){
	string s;
	cin >> s;
	int n = s.size();
	v.clear();
	for(int i=1; i<n; ++i){
		if(n % i == 0){
			v.emplace_back(i);
		}
	}
	int res = 1e9 + 100, c;
	for(auto x: v){
		int c_a = 0;
		for(int i=0; i<x; ++i){
			c = 0;
			for(int j=i; j<n; j+=x){
				c = max(c, ++a[s[j] - 'a']);
			}
			c_a += (n / x) - c;
			memset(a, 0, sizeof a);
		}
		res = min(res, c_a);
	}
	cout << res;
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
