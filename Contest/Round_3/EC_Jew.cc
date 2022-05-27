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

const int MxN = 2020;
string s;
int n, dp[MxN], slide[MxN];

inline void solution(){
	cin >> n >> s;
	s = " " + s;
	if(n > 300){
		return ;
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			int maxx = 0, now=0;
			for(int x=i; x<=j; ++x){
				if(s[x] == 'F'){
					now=0;
				}
				else{
					now++;
				}
				maxx = max(maxx, now);
			}
			dbg(i, j, maxx);
			answer += maxx;
		}
	}
	cout << answer;
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
