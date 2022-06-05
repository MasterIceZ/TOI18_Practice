/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sport Day
 * ALGO		: Greedy
 * DATE		: 27 May 2022
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

inline bool cmp(const pair<string, string> a, const pair<string, string> b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	return a.first < b.first;
}

inline void solution(){
	int n, cnt = 0;
	cin >> n;
	vector<pair<string, string>> v(n);
	for(auto &x: v){
		cin >> x.first >> x.second;
	}
	sort(v.begin(), v.end(), cmp);
	pair<string, string> last = make_pair("", "");
	for(auto x: v){
		if(last.second > x.first){
			continue;
		}
		cnt++;
		dbg(last, x);
		last = x;
	}
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
