/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_pair
 * ALGO		: Fenwick Tree
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

const int MxN = 100010;

struct Fenwick{
	ll tree[MxN];
	inline void update(int idx, ll v){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	inline ll read(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw, fw2;

pair<int, int> a[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].second >> a[i].first;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i){
		dbg(a[i]);
	}
	ll res = 0ll;
	for(int i=1; i<=n; ++i){
		res += a[i].second * (fw.read(100000) - fw.read(a[i].second)); // add a[i].second
		res += fw2.read(100000) - fw2.read(a[i].second); // add other
		fw.update(a[i].second, 1);
		fw2.update(a[i].second, a[i].second);
	}
	cout << res;
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
