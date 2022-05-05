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

const int MxN = 100010;
int slave[MxN], boss[MxN];

int getBoss(int now){
	if(boss[now] == now){
		return now;
	}
	return boss[now] = getBoss(boss[now]);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> slave[i];
		boss[i] = i;
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		int boss_u = getBoss(u);
		int boss_v = getBoss(v);
		if(boss_u == boss_v){
			cout << "-1";
		}
		else if(slave[boss_u] == slave[boss_v]){
			slave[min(boss_u, boss_v)] += slave[max(boss_u, boss_v)] / 2;
			boss[max(boss_u, boss_v)] = min(boss_u, boss_v);
			cout << min(boss_u, boss_v);
		}
		else if(slave[boss_u] < slave[boss_v]){
			slave[boss_v] += slave[boss_u] / 2;
			boss[boss_u] = boss_v;
			cout << boss_v;
		}
		else{
			slave[boss_u] += slave[boss_v] / 2;
			boss[boss_v] = boss_u;
			cout << boss_u;
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
