/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_chest
 * ALGO		: Sweepline, Math
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

struct EVP{
	ll idx, v;
	int type;
	bool operator < (const EVP& o) const {
		if(idx != o.idx){
			return idx < o.idx;
		}
		return type < o.type;
	}
	EVP(ll a, ll b, int c): idx(a), v(b), type(c) {}
};

ll a[11];

inline void add(ll now, int t){
	if(now <= 1ll){
		return ;
	}
	while(now % 2 == 0){
		now /= 2;
		a[2] += (t ? 1: -1);
	}
	while(now % 3 == 0){
		now /= 3;
		a[3] += (t ? 1: -1);
	}
	while(now % 5 == 0){
		now /= 5;
		a[5] += (t ? 1: -1);
	}
	while(now % 7 == 0){
		now /= 7;
		a[7] += (t ? 1: -1);
	}
}

inline void solution(){
	int n, m, x, l, r;
	cin >> n >> m;
	vector<EVP> line;
	for(int i=1; i<=n; ++i){
		cin >> x >> l >> r;
		line.emplace_back(l, x, 1);
		line.emplace_back(r + 1, x, 0);
	}
	sort(line.begin(), line.end());
	ll last = -1ll, maxx = -1ll, cnt = 0ll;
	for(auto x: line){
		dbg(x.idx, x.v, x.type);
		if(x.type){
			add(x.v, 1);
			last = x.idx;
			continue;
		}
		ll now = (a[2] + 1ll) * (a[3] + 1ll) * (a[5] + 1ll) * (a[7] + 1ll);
		dbg(now);
		if(now > maxx){
			maxx = now;
			cnt = 0ll;
		}
		if(now == maxx){
			cnt += (x.idx - last);
		}
		add(x.v, 0);
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
