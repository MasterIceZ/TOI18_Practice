/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_schedule
 * ALGO		: Fenwick Tree, Sweepline
 * DATE		: 4 May 2022
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

const int MxN = 500050;
struct FenwickTree{
	int tree[MxN];
	inline void update(int idx, int v){
		for(; idx <= 500000; idx+=idx&-idx){
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
} fw;
struct EventPoint{
	int idx, v, q;
	bool operator < (const EventPoint& o) const {
		if(idx != o.idx){
			return idx < o.idx;
		}
		return v < o.v;
	}
	EventPoint(int a, int b, int c): idx(a), v(b), q(c) {}
};
bitset<MxN> use;
vector<EventPoint> line;

inline void solution(){
	int n, k, m, x;
	cin >> n >> k >> m;
	for(int i=1, l, r; i<=n; ++i){
		cin >> l >> r;
		line.emplace_back(l, 1, i);
		line.emplace_back(r + 1, -1, i);
	}
	sort(line.begin(), line.end());
	for(auto x: line){
		if(x.v < 0){
			if(use[x.q]){
				fw.update(x.idx, -1);
			}
		}
		else{
			if(fw.read(x.idx) < k){
				fw.update(x.idx, 1);
				use[x.q] = true;
			}
		}
	}
	while(m--){
		cin >> x;
		cout << (use[x] ? "Y": "N") << " ";
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
