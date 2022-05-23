/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_chest
 * ALGO		: Sweepline
 * DATE		: 23 May 2022
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

// don't try this at home
#define int ll

struct EventPoint{
	int idx, v, type;
	bool operator < (const EventPoint& o) const {
		if(idx != o.idx){
			return idx < o.idx;
		}
		return type < o.type;
	}
	EventPoint(int a, int b, int c): idx(a), v(b), type(c) {}
};

int value[11];
inline void process(int v, int type){
	for(; v%2==0; v/=2){
		value[1] += (type? 1: -1);
	}
	for(; v%3==0; v/=3){
		value[2] += (type? 1: -1);
	}
	for(; v%5==0; v/=5){
		value[3] += (type? 1: -1);
	}
	for(; v%7==0; v/=7){
		value[4] += (type? 1: -1);
	}
}

inline void solution(){
	int n, m, l, r, x;
	cin >> n >> m;
	vector<EventPoint> line;
	for(int i=1; i<=n; ++i){
		cin >> x >> l >> r;
		line.emplace_back(l, x, 1);
		line.emplace_back(r + 1, x, 0);
	}
	sort(line.begin(), line.end());
	int last = -1, maxx = -1, cnt = 0;
	for(auto x: line){
		dbg(x.idx, x.v, x.type);
		if(x.type == 1){
			last = x.idx;
		}
		else{
			int now = (value[1] + 1) * (value[2] + 1) * (value[3] + 1) * (value[4] + 1);
			dbg(now);
			if(now > maxx){
				maxx = now;
				cnt = 0;
			}
			if(now == maxx){
				cnt += (x.idx - last);
			}
		}
		process(x.v, x.type);
	}
	cout << maxx << " " << cnt;
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
