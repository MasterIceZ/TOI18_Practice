/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_pipe
 * ALGO		: Minimum Spanning Tree, Prim's Algorithm
 * DATE		: 13 May 2022
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

const int MxN = 15050;
pair<int, int> p[MxN];
int w[MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	memset(w, 0x3f, sizeof w);
	w[1] = 0;
	for(int i=2; i<=n; ++i){
		int minn = 1e9 + 100, idx = -1;
		for(int j=i; j<=n; ++j){
			w[j] = min(w[j], abs(p[i - 1].first - p[j].first) + abs(p[i - 1].second - p[j].second));
			if(w[j] < minn){
				minn = w[j];
				idx = j;
			}
		}
		swap(w[i], w[idx]);
		swap(p[i], p[idx]);
	}
	sort(w + 1, w + n + 1);
	cout << accumulate(w + 1, w + n - k + 2, 0);
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
