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

const ll MOD = 1e9 + 7;

struct Matrix{
	ll a[10][10];
	Matrix(){
		memset(a, 0, sizeof a);
		for(int i=1; i<=9; ++i){
			a[i][i] = 1ll;
		}
	}
	inline void s(Matrix A){
		memcpy(a, A.a, sizeof a);
	}
};

Matrix operator * (const Matrix A, const Matrix B){
	Matrix res;
	for(int i=1; i<=2; ++i){
		for(int j=1; j<=2; ++j){
			ll t = 0ll;
			for(int k=1; k<=2; ++k){
				t = (t + (A.a[i][k] * B.a[k][j]) % MOD) % MOD;
			}
			res.a[i][j] = t;
		}
	}
	return res;
}

const int MxN = 66;
Matrix mem[MxN];
ll l, r;

Matrix tr;

inline void solution(){
	cin >> l >> r;
	l = l - 1;
	Matrix res_1, res_2;
	res_1.s(tr); res_2.s(tr);
	dbg(l, r);
	for(ll i=62; i>=0; --i){
		if(r & (1ll << i)){
			res_1 = res_1 * mem[i];
		}
	}
	for(ll i=62; i>=0; --i){
		if(l & (1ll << i)){
			res_2 = res_2 * mem[i];
		}
	}
	cout << ((res_1.a[1][1] - res_2.a[1][1]) % MOD + MOD) % MOD;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	mem[0].a[1][1] = 1; mem[0].a[1][2] = 1;
	mem[0].a[2][1] = 1; mem[0].a[2][2] = 0;
	for(int i=1; i<=62; ++i){
		mem[i] = mem[i - 1] * mem[i - 1];
	}
	tr.a[1][1] = 9; tr.a[1][2] = 6;
	tr.a[2][1] = 6, tr.a[2][2] = 0;
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
