/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Sterile City
 * ALGO		: Floyd Warshall
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

const int MxN = 550;
int mem[MxN][3], dist[MxN][MxN];
bitset<MxN> ok;

inline void solution(){
	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	memset(mem, -1, sizeof mem);
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=n; ++i){
		dist[i][i] = 0;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[v][u], w);
	}
	ok = 0;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		ok[x] = true;
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i == j || !ok[i] || !ok[j]){
				continue;
			}
			if(mem[i][0] == -1 || dist[i][mem[i][0]] > dist[i][j]){
				mem[i][2] = mem[i][1];
				mem[i][1] = mem[i][0];
				mem[i][0] = j;
			}
			else if(mem[i][1] == -1 || dist[i][mem[i][1]] > dist[i][j]){
				mem[i][2] = mem[i][1];
				mem[i][1] = j;
			}
			else if(mem[i][2] == -1 || dist[i][mem[i][2]] > dist[i][j]){
				mem[i][2] = j;
			}
		}
	}
	int answer = 1e9 + 100;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i == j || !ok[i] || !ok[j] || dist[i][j] >= 1e9 + 100){
				continue;
			}
			for(int x=1; x<=n; ++x){
				if(!ok[x] || x == i || x == j){
					continue;
				}
				if(mem[x][0] != i && mem[x][0] != j && mem[x][0] != -1){
					answer = min(answer, dist[i][j] + dist[x][mem[x][0]]);
				}
				else if(mem[x][1] != i && mem[x][1] != j && mem[x][1] != -1){
					answer = min(answer, dist[i][j] + dist[x][mem[x][1]]);
				}
				else if(mem[x][2] != i && mem[x][2] != j && mem[x][2] != -1){
					answer = min(answer, dist[i][j] + dist[x][mem[x][2]]);
				}
			}
		}
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
