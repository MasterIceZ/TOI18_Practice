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

struct Bomb{
	int i, j, idx;
	Bomb(int a=0, int b=0, int c=0): i(a), j(b), idx(c) {}
};

const int MxN = 1000010;
int p[MxN];
Bomb b[MxN];
bitset<MxN> used;

inline bool cmpx(const Bomb a, const Bomb b){
	if(a.i != b.i){
		return a.i < b.i;
	}
	return a.j < b.j;
}

inline bool cmpy(const Bomb a, const Bomb b){
	if(a.j != b.j){
		return a.j < b.j;
	}
	return a.i < b.i;
}

int fr(int u){
	return u == p[u]? u: p[u] = fr(p[u]);
}

inline void solution(){
	int n, m, k, l, q, x, t, cnt;
	cin >> n >> m >> k >> l;
	for(int i=1; i<=k; ++i){
		cin >> b[i].i >> b[i].j;
		b[i].idx = i;
	}
	iota(p + 1, p + k + 1, 1);
	sort(b + 1, b + k + 1, cmpx);
	for(int i=2; i<=k; ++i){
		if(b[i].i == b[i - 1].i && b[i].j - b[i - 1].j <= l){
			p[fr(b[i].idx)] = fr(b[i - 1].idx);
		}
	}
	sort(b + 1, b + k + 1, cmpy);
	for(int i=2; i<=k; ++i){
		if(b[i].j == b[i - 1].j && b[i].i - b[i - 1].i <= l){
			p[fr(b[i].idx)] = fr(b[i - 1].idx);
		}
	}
	for(int i=1; i<=k; ++i){
		fr(i);
	}
	dbg(to_string(p, 1, k));
	cin >> q;
	while(q--){
		used = 0, cnt = 0;
		cin >> x;
		while(x--){
			cin >> t;
			if(used[p[t]]){
				continue;
			}
			cnt++;
			used[p[t]] = true;
		}
		cout << cnt << "\n";
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
