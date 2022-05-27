/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Command
 * ALGO		: Math
 * DATE		: 26 May 2022
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

ll n, t;
vector<ll> answer;

inline void dv(ll &a, ll b){
	while(a % b == 0){
		a /= b;
		answer.emplace_back(b);
	}
}

inline void solution(){
	cin >> t >> n;
	dv(n, 4);
	dv(n, 6);
	ll sq = sqrt(n);
	for(int i=2; i<=sq; ++i){
		dv(n, i);
	}
	if(n != 1){
		answer.emplace_back(n);
	}
	sort(answer.begin(), answer.end());
	for(auto x: answer){
		cout << "AC";
		while(x--){
			cout << "V";
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
