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

const int MxN = 110;
pair<int, int> a[MxN];
int t[1010];

inline void solution(){
#ifndef _DEBUG
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
		t[a[i].first]++, t[a[i].second]--;
	}
	for(int i=1; i<1000; ++i){
		t[i] += t[i - 1];
	}
	int maxx = 0;
	for(int i=1; i<=n; ++i){
		for(int x=a[i].first; x<a[i].second; ++x){
			t[x]--;
		}
		int cnt = 0;
		for(int x=0; x<1000; ++x){
			cnt += (t[x] ? 1: 0);
		}
		maxx = max(maxx, cnt);
		for(int x=a[i].first; x<a[i].second; ++x){
			t[x]++;
		}
	}
	cout << maxx;
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
