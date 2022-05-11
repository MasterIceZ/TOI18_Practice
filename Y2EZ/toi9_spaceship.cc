/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_spaceship
 * ALGO		: Brute Force
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

int k, s_x, s_y, s_z, n, answer = 1e9 + 100;
int x[22], y[22], z[22], a[22], b[22], c[22];
bitset<22> visited;

inline int power(int a){
	return a * a;
}

void rec(int cost, int h_x, int h_y, int h_z, int p_x, int p_y, int p_z){
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		visited[i] = true;
		int next_cost = cost + power(p_x - x[i]) + power(p_y - y[i]) + power(p_z - z[i]);
		if(h_x + a[i] >= k && h_y + b[i] >= k && h_z + c[i] >= k){
			answer = min(answer, next_cost);
		}
		else{
			rec(next_cost, h_x + a[i], h_y + b[i], h_z + c[i], x[i], y[i], z[i]);
		}
		visited[i] = false;
	}
}

inline void solution(){
	cin >> k >> s_x >> s_y >> s_z >> n;
	for(int i=1; i<=n; ++i){
		cin >> x[i] >> y[i] >> z[i] >> a[i] >> b[i] >> c[i];
	}
	rec(0, 0, 0, 0, s_x, s_y, s_z);
	cout << answer;
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
