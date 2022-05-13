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

const int MxN = 1010;
char a[MxN][MxN];
int comp[MxN][MxN];
pair<int, int> ul[MxN * MxN], dr[MxN * MxN];
queue<pair<int, int>> q;
int n, m, it = 0;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline void bfs(int i, int j){
	q.emplace(i, j);
	comp[i][j] = ++it;
	ul[it] = make_pair(i, j);
	dr[it] = make_pair(i, j);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == '#' || comp[ii][jj]){
				continue;
			}
			comp[ii][jj] = it;
			ul[it] = make_pair(min(ul[it].first, ii), min(ul[it].second, jj));
			dr[it] = make_pair(max(dr[it].first, ii), max(dr[it].second, jj));
			q.emplace(ii, jj);
		}
	}
}

inline void solution(){
	int q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(!comp[i][j] && a[i][j] != '#'){
				bfs(i, j);
			}
		}
	}
//	for(int i=1; i<=it; ++i){
//		cout << ul[i].first << " " << ul[i].second << "\n";
//	}
//	for(int i=1; i<=it; ++i){
//		cout << dr[i].first << " " << dr[i].second << "\n";
//	}
	while(q--){
		int a, b, c, d, x, y;
		cin >> a >> b >> c >> d >> x >> y;
		int cp = comp[x][y];
		dbg(ul[cp], dr[cp]);
		if(ul[cp].first <= a || ul[cp].second <= b || dr[cp].first >= c || dr[cp].second >= d){
			cout << "YES";
		}
		else{
			cout << "NO";
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
