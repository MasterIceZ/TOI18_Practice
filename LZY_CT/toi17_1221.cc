/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi17_1221
 * ALGO		: Floyd Warshall
 * DATE		: 30 May 2022
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

const int MxN = 550;
int a[MxN], dist[MxN][MxN], cnt[MxN][MxN];

inline void solution(){
	int n, m, q, x, y, u, v, w;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dist[i][j] = a[i] + a[j];
			cnt[i][j] = 2;
		}
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[v][u], w);
		cnt[u][v] = 2;
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					cnt[i][j] = cnt[i][k] + cnt[k][j]; 
				}
				else if(dist[i][j] == dist[i][k] + dist[k][j]){
					cnt[i][j] = max(cnt[i][j], cnt[i][k] + dist[k][j]);
				}
			}
		}
	}
	while(q--){
		cin >> x >> y;
		cout << dist[x][y] << " " << cnt[x][y] << "\n";
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
