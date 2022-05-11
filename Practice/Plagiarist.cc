/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Plagiarist
 * ALGO		: Rope
 * DATE		: 9 May 2022
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

const int MxN = 200020;

struct FenwickTree{
	int tree[MxN];
	inline void update(int idx, int v){
		for(; idx<=200000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	inline int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
	// Build Fenwick Tree in O(n)
	FenwickTree(){
		for(int i=1; i<=200000; ++i){
			tree[i] += 1;
			int idx = i + (i & -i);
			if(idx <= 200000){
				tree[idx] += tree[i];
			}
		}
	}
} fw;

int a[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		int l = 1, r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			int res = fw.read(mid);
			if(res > x){
				r = mid;
			}
			else if(res < x){
				l = mid + 1;
			}
			else{
				if(fw.read(mid - 1) < x){
					fw.update(mid, -1);
					l = mid;
					break;
				}
				else{
					r = mid;
				}
			}
		}
		cout << a[l] << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
