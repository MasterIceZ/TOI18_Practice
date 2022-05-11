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

inline int calc(string a, string b){
	int res = 0;
	for(int i=0; i<a.size(); ++i){
		int x = a[i] + 26;
		int y = b[i] + 26;
		res += abs(x - y);
	}
	return res;
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	vector<string> v(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	int answer = 1e9 + 100;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			answer = min(answer, calc(v[i], v[j]));
		}
	}
	cout << answer;
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
