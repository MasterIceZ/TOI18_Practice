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
	ll a[5][5];
	Matrix(){
		for(int i=1; i<=4; ++i){
			a[i][i] = i;
		}
	}
	inline void set_value(const ll b[][5]){
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
			for(int k=1;k<4; ++k){
				t = (t + (A.a[i][k] * B.a[k][j]) % MOD) % MOD;
			}
			res.a[i][j] = t;
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
		{0, e, f, g, h},
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0}
	};
	mem[1].set_value(mtx);

	for(int i=2; i<=62; ++i){
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
		for(ll i=62; i>=1; --i){
			if(x & (1ll << (i - 1))){
				dbg(i);
				res = res * mem[i];
			}
		}
		ll sum = (e * res.a[1][1] + f * res.a[1][2]) % MOD;
		sum = (sum + g * res.a[1][3] + h * res.a[1][4]) % MOD;
		cout << sum << "\n";
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
