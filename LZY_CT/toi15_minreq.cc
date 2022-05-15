/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_minreq
 * ALGO		: Brute Force
 * DATE		: 14 May 2022
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

const int MxN = 1e7 + 10;
int n, m, x;
int p[22], a[22], l[22], s[MxN], qs[MxN], qry[22];
bitset<22> used;

inline bool check(int t){
	used = 0;
	for(int i=1, j; i<=n; ++i){
		for(j=1; j<=n; ++j){
			if(used[j]){
				continue;
			}
			int le = p[i], ri = p[i + 1], cnt = 0;
			bool ok = true;
			while(ok && le < ri){
				cnt += 1;
				int idx = upper_bound(qs + le, qs + ri, l[j] - a[i] + qs[le - 1]) - qs;
				if(idx == le){
					ok = false;
				}
				le = idx;
			}
			if(ok && cnt <= t){
				used[j] = true;
				break;
			}
		}
		if(j == 1 + n){
			return false;
		}
	}
	return true;
}

inline bool ok(int t){
	for(int i=1; i<=n; ++i){
		cin >> p[i];
	}
	p[n + 1] = m + 1;
	do{
		if(check(t)){
			return true;
		}
	}while(next_permutation(a + 1, a + n + 1));
	return false;
}

inline void solution(){
	cin >> n >> m >> x;
	for(int i=1; i<=n; ++i){
		cin >> l[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> s[i];
		qs[i] = s[i] + qs[i - 1];
	}
	sort(l + 1, l + n + 1);
	for(int i=1; i<=x; ++i){
		cin >> qry[i];
	}
	for(int i=1; i<=x; ++i){
		cout << (ok(qry[i]) ? "P": "F") << "\n";
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
