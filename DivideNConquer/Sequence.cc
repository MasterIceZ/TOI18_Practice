/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sequence
 * ALGO		: Divide and Conquer
 * DATE		: 25 May 2022
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

const ll MOD = 2553;

struct Matrix{
	ll a[10][10];
	Matrix(){
		memset(a, 0, sizeof a);
		for(int i=1; i<=4; ++i){
			a[i][i] = 1ll;
		}
	}
	inline void set_value(const ll b[5][5]){
		for(int i=1; i<=4; ++i){
			for(int j=1; j<=4; ++j){
				a[i][j] = b[i][j];
			}
		}
	}
};

Matrix operator * (const Matrix A, const Matrix	B){
	Matrix res;
	for(int i=1; i<=4; ++i){
		for(int j=1; j<=4; ++j){
			ll t = 0ll;
			for(int k=1;k<=4; ++k){
				t = t + (A.a[i][k] * B.a[k][j]);
			}
			res.a[i][j] = t % MOD;
		}
	}
	return res;
}

Matrix mem[65], base;

inline void solution(){
	ll a, b, c, d, e, f, g, h, x;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	
	const ll mtx[5][5] = {
		{0, 0, 0, 0, 0},
		{0, e, 1, 0, 0},
		{0, f, 0, 1, 0},
		{0, g, 0, 0, 1},
		{0, h, 0, 0, 0}
	};
	const ll bx[5][5] = {
		{0, 0, 0, 0, 0},
		{0, d, c, b, a},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	base.set_value(bx);
	mem[0].set_value(mtx);

	for(int i=1; i<=62; ++i){
		mem[i] = mem[i - 1] * mem[i - 1];
	}

	int q;
	cin >> q;
	while(q--){
		cin >> x;
		if(x == 1){
			cout << a << "\n";
			continue;
		}
		if(x == 2){
			cout << b << "\n";
			continue;
		}
		if(x == 3){
			cout << c << "\n";
			continue;
		}
		if(x == 4){
			cout << d << "\n";
			continue;
		}
		Matrix res;
		res.set_value(bx);
		x = x - 4; // x = 5
		for(ll i=62; i>=0; --i){
			if(x & (1ll << i)){
				dbg(i);
				res = res * mem[i];
			}
		}
//		res = res * base;
		cout << res.a[1][1] << "\n";
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
