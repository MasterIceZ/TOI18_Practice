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
int n;
ll qs[MxN][MxN], slide[MxN][MxN];

inline void solution(){
	cin >> n >> s;
	s = " " + s;
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			if(s[j] == 'F'){
				qs[i][j] = 0;
			}
			else{
				qs[i][j] = qs[i][j - 1] + 1ll;
			}
			slide[i][j] = max(slide[i][j - 1], qs[i][j]);
		}
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			dbg(i, j, slide[i][j]);
			answer = answer + slide[i][j];
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
