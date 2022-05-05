/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi8_fighter
 * ALGO		: Implementation
 * DATE		: 5 May 2022
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

int p[3], c[3];

inline void solution(){
	int n, answer, end_point;
	cin >> n;
	bool finished = false;
	p[0] = n, p[1] = n;
	for(int i=1, x; i<=2*n; ++i){
		cin >> x;
		if(finished){
			continue;
		}
		c[x % 2]++;
		c[(x + 1) % 2] = 0;
		p[(x + 1) % 2] -= (c[x % 2] >= 3 ? 3: 1);
		if(p[(x + 1) % 2] <= 0){
			answer = x % 2;
			finished = true;
			end_point = x;
		}
	}
	cout << answer << "\n" << end_point;
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
