/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi17_wall
 * ALGO		: Breadth First Search
 * DATE		: 12 May 2022
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

const int MxN = 1010;

int n, m, comp[MxN][MxN], cnt[MxN * MxN];
bool water[MxN][MxN];
queue<pair<int ,int>> q;
char a[MxN][MxN];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline void bfs(int i, int j, int t){
	q.emplace(i, j);
	comp[i][j] = t;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first, jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '.' || comp[ii][jj]){
				continue;
			}
			q.emplace(ii, jj);
			comp[ii][jj] = t;
		}
	}
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	q.emplace(1, 1);
	water[1][1] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first, jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == 'X' || water[ii][jj]){
				continue;
			}
			water[ii][jj] = true;
			q.emplace(ii, jj);
		}
	}
	int it = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 'X' && !comp[i][j]){
				bfs(i, j, ++it);
			}
		}
	}
	int maxx = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(water[i][j] || !comp[i][j]){
				continue;
			}
			for(int k=0; k<4; ++k){
				int ii = di[k] + i, jj = dj[k] + j;
				cnt[comp[i][j]] += (water[ii][jj] && comp[i][j]);
				maxx = max(maxx, cnt[comp[i][j]]);
			}
		}
	}
	cout << maxx;
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
