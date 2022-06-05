/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sqrt Decomposition
 * ALGO		: Square Root Decomposition
 * DATE		: 29 May 2022
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

struct SQD{
	vector<int> cluster, a;
	int _sq, _n;
	void init(int n){
		_sq = sqrt(n);
		_n = n;
		cluster.resize(_sq + 2);
		a.resize(_n + 10);
	}
	void update(int idx, int v){
		int cl = idx / _sq;
		a[idx] = v;
		cluster[cl] = -1e9 - 100;
		for(int i=idx/_sq*_sq; i<idx/_sq*_sq+_sq; ++i){
			cluster[cl] = max(cluster[cl], a[i]);
		}
	}
	int read(int l, int r){
		int res = -1e9 - 100;
		for(int i=l; i<=r; ){
			if(i % _sq == 0 && i + _sq - 1 <= r){
				res = max(res, cluster[i / _sq]);
				i += _sq;
			}
			else{
				res = max(res, a[i]);
				i++;
			}
		}
		return res;
	}
} sq;

inline void solution(){
	int n, q, idx, v, l, r;
	char opr;
	cin >> n >> q;
	sq.init(n);
	while(q--){
		cin >> opr;
		if(opr == 'U'){
			cin >> idx >> v;
			sq.update(idx, v);
		}
		else{
			cin >> l >> r;
			cout << sq.read(l, r) << "\n";
		}
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
