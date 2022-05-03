/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi4_mountain
 * ALGO		: Implementation
 * DATE		: 4 May 2022
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

const int MxN = 110;
char a[MxN][MxN];

inline void solution(){
	int n, hei = 0, wid = 0;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(auto &x: v){
		cin >> x.first >> x.second;
		hei = max(hei, x.second);
		wid = max(wid, x.first + 2 * x.second);
	}
	memset(a, '.', sizeof a);
	sort(v.begin(), v.end());
	for(auto x: v){
		int cur = x.first + 2 * x.second;
		for(int i=1; i<=x.second; ++i){
			for(int j=x.first+i-1; j<=cur-i; ++j){
				if(j == x.first + i - 1){
					if(a[i][j] == '.'){
						a[i][j] = '/';
					}
					else if(a[i][j] == '\\'){
						a[i][j] = 'v';
					}
					else{
						a[i][j] = 'X';
					}
				}
				else if(j == cur - i){
					if(a[i][j] == '.'){
						a[i][j] = '\\';
					}
					else if(a[i][j] == '/'){
						a[i][j] = 'v';
					}
					else{
						a[i][j] = 'X';
					}
				}
				else{
					a[i][j] = 'X';
				}
			}
		}
	}
	for(int i=hei; i>=1; --i){
		for(int j=1; j<wid; ++j){
			cout << a[i][j];
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
