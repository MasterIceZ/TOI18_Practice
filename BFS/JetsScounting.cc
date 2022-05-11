/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jet's Scounting
 * ALGO		: Breadth First Search
 * DATE		: 6 May 2022
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

struct Tile{
	int i, j, s;
	Tile(int a, int b, int c): i(a), j(b), s(c) {}
};

const int MxN = 330;
char a[MxN][MxN];
int n, m, dist[MxN][MxN][5]; // (up / down), (right / left), ...
int now_dist;
queue<Tile> qu;

const int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dj[] = {0, 0, 1, -1, -1, 1, 1, -1};

inline int find_direction(int state){
	if(state == 0){
		return 2;
	}
	if(state == 1){
		return 0;
	}
	if(state == 2){
		return 6;
	}
	return 4;
}

inline int find_state(int state){
	if(state == 0){
		return 1;
	}
	if(state == 1){
		return 0;
	}
	if(state == 2){
		return 3;
	}
	return 2;
}

inline void walk(int i, int j, int dir, int state){
	int nxt_state = find_state(state);
	int ii = di[dir] + i, jj = dj[dir] + j;
	while(1){
		if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == '#' || dist[ii][jj][nxt_state] != -1){
			return ;
		}
		dist[ii][jj][nxt_state] = now_dist + 1;
		qu.emplace(ii, jj, nxt_state);
		ii += di[dir], jj += dj[dir];
	}
}

inline int hsh(int x){
	if(x == -1){
		return (int) 1e9;
	}
	return x;
}

inline void solution(){
	int q, x, y;
	cin >> n >> m >> q;
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'J'){
				for(int k=0; k<4; ++k){
					dist[i][j][k] = 0;
					qu.emplace(i, j, k);
				}
			}
		}
	}
	while(!qu.empty()){
		Tile now = qu.front();
		qu.pop();
		now_dist = dist[now.i][now.j][now.s];
		int nxt = find_direction(now.s);
		walk(now.i, now.j, nxt, now.s);
		walk(now.i, now.j, nxt + 1, now.s);
	}
	while(q--){
		cin >> x >> y;
		int res = min({hsh(dist[x][y][0]), hsh(dist[x][y][1]), hsh(dist[x][y][2]), hsh(dist[x][y][3])});
		cout << (res == (int) 1e9 ? -1: res - 1) << "\n";
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
