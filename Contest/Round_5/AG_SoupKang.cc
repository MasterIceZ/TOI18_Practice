/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Soup Kang
 * ALGO		: Constructive Algorithm
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

const int MxN = 550;
int n, m, q, x, y;
char a[MxN][MxN];

struct Garden{
	int from_left[MxN][MxN], from_right[MxN][MxN];
	inline void update(int i){
		int last = 1e9 + 100;
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 'x'){
				last = j;
			}
			from_left[i][j] = last;
		}
		last = 1e9 + 100;
		for(int j=m; j>=1; --j){
			if(a[i][j] == 'x'){
				last = j;
			}
			from_right[i][j] = last;
		}
	}
	inline void build(){
		for(int i=1; i<=n; ++i){
			update(i);
		}
	}
	inline int make(int a, int b, int c, int d){
		return (a - c) * (a - c) + (b - d) * (b - d);
	}
	inline int read(int x, int y){
		int answer = 1e9 + 100;
		for(int i=1; i<=n; ++i){
			if(from_left[i][y] != 1e9 + 100){
				answer = min(answer, make(x, y, i, from_left[i][y]));
			}
			if(from_right[i][y] != 1e9 + 100){
				answer = min(answer, make(x, y, i, from_right[i][y]));
			}
		}
		return answer;
	}
} garden;

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	garden.build();
	cin >> q;
	while(q--){
		cin >> x >> y;
		cout << garden.read(x, y) << "\n";
		a[x][y] = 'x';
		garden.update(x);
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
