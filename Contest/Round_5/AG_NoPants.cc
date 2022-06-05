/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_No Pants
 * ALGO		: Divide and Conquer
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

const int MxN = 255;
struct Matrix{
	double a[255][255];
	Matrix(){
		for(int i=1; i<=254; ++i){
			for(int j=1; j<=254; ++j){
				a[i][j] = 0.0;
			}
		}
		for(int i=1; i<=254; ++i){
			a[i][i] = 1.0;
		}
	}	
};

int n, t;
double a[MxN];

Matrix operator * (const Matrix A, const Matrix B){
	Matrix res;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			res.a[i][j] = 0.0;
			for(int k=1; k<=n; ++k){
				res.a[i][j] += A.a[i][k] * B.a[k][j];
			}
		}
	}
	return res;
}

Matrix mem[22], base;

inline void solution(){
	cin >> n >> t;
	t = t - 1;
	for(int i=1; i<=n; ++i){
		cin >> base.a[i][i];
		base.a[i][i] *= 1.0;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> mem[0].a[i][j];
		}
	}
	for(int i=1; i<=20; ++i){
		mem[i] = mem[i - 1] * mem[i - 1];
	}
	Matrix res;
	for(int state=20; state>=0; --state){
		if(t & (1 << state)){
			res = res * mem[state];
		}
	}
	res = base * res;
	for(int j=1; j<=n; ++j){
		double sum = 0.0;
		for(int i=1; i<=n; ++i){
			sum = sum + res.a[i][j];
		}
		cout << fixed << setprecision(2) << sum << "\n";
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
