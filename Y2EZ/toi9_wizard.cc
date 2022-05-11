/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_wizards
 * ALGO		: Hash
 * DATE		: 7 May 2022
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

const int MxN = 1550;
int x[5][MxN], y[5][MxN];
const int HASH_SIZE = 5e6 + 11;

struct Hash_Table{
	pair<int, int> real_value[HASH_SIZE];
	int table[HASH_SIZE];
	inline int encrypt(int a, int b){
		return (HASH_SIZE + (a + ((b * 3) % HASH_SIZE) % HASH_SIZE) % HASH_SIZE) % HASH_SIZE;
	}
	inline void insert(int val_x, int val_y, int i, int j){
		int k = encrypt(val_x, val_y);
		while(table[k]){
			k = (k + 1) % HASH_SIZE;
		}
		table[k] = (1500 * i) + j + 1;
		real_value[k] = make_pair(val_x, val_y);
	}
	inline int read(int val_x, int val_y){
		int k = encrypt(val_x, val_y);
		while(table[k]){
			if(real_value[k] == make_pair(val_x, val_y)){
				return table[k] - 1;
			}
			k = (k + 1) % HASH_SIZE;
		}
		return -1;
	}
} mp;

inline void solution(){
	int xt, yt, n;
	cin >> xt >> yt >> n;
	for(int k=0; k<4; ++k){
		for(int i=0; i<n; ++i){
			cin >> x[k][i] >> y[k][i];
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			mp.insert(x[0][i] + x[1][j], y[0][i] + y[1][j], i, j);
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int res = mp.read(xt - x[2][i] - x[3][j], yt - y[2][i] - y[3][j]);
			if(res != -1){
				cout << x[0][res / 1500] << " " << y[0][res / 1500] << "\n";
				cout << x[1][res % 1500] << " " << y[1][res % 1500] << "\n";
				cout << x[2][i] << " " << y[2][i] << "\n";
				cout << x[3][j] << " " << y[3][j];
				return ;
			}
		}
	}
	while(1);
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
