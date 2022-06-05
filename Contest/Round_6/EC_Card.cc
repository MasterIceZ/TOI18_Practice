/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Card
 * ALGO		: 
 * DATE		: 28 May 2022
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

const int MxN = 10010;
bitset<2 * MxN> used;
int a[MxN], b[MxN];

inline void solution(){
	int n, cnt = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> b[i];
		used[b[i]] = true;
		if(i % 2 == 0){
			b[i] = -b[i];
		}
	}
	int it = 0;
	for(int i=1; i<=2*n; ++i){
		if(used[i]){
			continue;
		}
		a[++it] = i;
		if(it <= n / 2){
			a[it] = -a[it];
		}
	}
	sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
	dbg(to_string(a, 1, n));
	dbg(to_string(b, 1, n));
	for(int i=1; i<=n; ++i){
		if(a[i] > b[i]){
			dbg(a[i], b[i]);
			cnt++;
		}
	}
	cout << cnt;
	used = 0;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
