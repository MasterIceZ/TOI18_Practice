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

const int MxN = 200020;

pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b){
	return make_pair(a.first + b.first, a.second + b.second);
}

struct Seg{
	pair<int, int> tree[4 * MxN], lazy[4 * MxN];
	void update(int l, int r, int wl, int wr, pair<int, int> v, int idx){
		if(l > wr || r < wl || l > r){
			return ;
		}
		if(lazy[idx] != make_pair(0, 0)){
			if(l != r){
				lazy[idx << 1] = lazy[idx << 1] + lazy[idx];
				lazy[idx << 1 | 1] = lazy[idx << 1 | 1] + lazy[idx];
			}
			tree[idx << 1] = tree[idx << 1] + make_pair(lazy[idx].first * (r - l + 1), lazy[idx].second);
			tree[idx << 1 | 1] = tree[idx << 1 | 1] + make_pair(lazy[idx].first * (r - l + 1), lazy[idx].second);
			lazy[idx] = make_pair(0, 0);
		}
		if(wl <= l && r <= wr){
			dbg(wl, wr);
			if(l != r){
				lazy[idx] = lazy[idx] + make_pair((r - l + 1) * v.first, v.second);
			}
			tree[idx] = tree[idx] + make_pair((r - l + 1) * v.first, v.second);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, v, idx << 1);
		update(mid + 1, r, wl, wr, v, idx << 1 | 1);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	pair<int, int> read(int l, int r, int wl, int wr, int idx){
		if(l > r || wl > r || l > wr){
			return make_pair(0, 0);
		}
		if(lazy[idx] != make_pair(0, 0)){
			if(l != r){
				lazy[idx << 1] = lazy[idx << 1] + lazy[idx];
				lazy[idx << 1 | 1] = lazy[idx << 1 | 1] + lazy[idx];
			}
			tree[idx << 1] = tree[idx << 1] + make_pair(lazy[idx].first * (r - l + 1), lazy[idx].second);
			tree[idx << 1 | 1] = tree[idx << 1 | 1] + make_pair(lazy[idx].first * (r - l + 1), lazy[idx].second);
			lazy[idx] = make_pair(0, 0);
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return read(l, mid, wl, wr, idx << 1) + read(mid + 1, r, wl, wr, idx << 1 | 1);
	}
} seg;

inline void solution(){
	int n;
	cin >> n;
	seg.update(1, n, 1, 1, {0, 1}, 1);
	int it = 1;
	for(int i=1, opr, a, b; i<=n; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> a >> b;
			seg.update(1, n, 1, a, {b, 0}, 1);
		}
		else if(opr == 2){
			cin >> a;
			seg.update(1, n, it + 1, it + 1, {a, 1}, 1);
			it++;
		}
		else{
			auto now = seg.read(1, n, it, it, 1);
			seg.update(1, n, it, it, {-now.first, -now.second}, 1);
			it--;
		}
		auto now = seg.read(1, n, 1, n, 1);
//		cout << now.first << " " << now.second << "\n";
		for(int x=1; x<=it; ++x){
			cout << seg.read(1, n, x, x, 1).first << " ";
		}
		cout << "\n";
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
