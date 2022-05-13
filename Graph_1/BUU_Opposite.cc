/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BUU Opposite
 * ALGO		: Breadth First Search
 * DATE		: 11 May 2022
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

struct Node{
	pair<int, int> A, B;
	Node(pair<int, int> a, pair<int, int> b): A(a), B(b) {}
};

const int MxN = 44;
char a[MxN][MxN];
int n, m, dist[MxN][MxN][MxN][MxN], dist2[MxN][MxN][MxN][MxN], now_dist;
pair<int, int> A, B;
queue<pair<int, int>> q;
queue<Node> qq;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline bool inRange(int i, int j){
	return (i >= 1 && j >= 1 && i <= n && j <= m && a[i][j] != '#');
}

inline void Add(pair<int, int> a, pair<int, int> b){
	if(dist2[a.first][a.second][b.first][b.second] != -1){
		return ;
	}
	dist2[a.first][a.second][b.first][b.second] = 1 + now_dist;
	qq.emplace(a, b);
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'A'){
				A = make_pair(i, j);
			}
			else if(a[i][j] == 'B'){
				B = make_pair(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			q.emplace(i, j);
			dist[i][j][i][j] = 0;
			while(!q.empty()){
				pair<int, int> now = q.front();
				q.pop();
				for(int k=0; k<4; ++k){
					int ii = di[k] + now.first, jj = dj[k] + now.second;
					if(!inRange(ii, jj) || dist[i][j][ii][jj] != -1){
						continue;
					}
					dist[i][j][ii][jj] = dist[i][j][now.first][now.second] + 1;
					q.emplace(ii, jj);
				}
			}
		}
	}
	// check reachable
	if(dist[A.first][A.second][B.first][B.second] == -1){
		dbg("Cannot Reach");
		cout << "-1 0";
		return ;
	}
	memset(dist2, -1, sizeof dist2);
	qq.emplace(A, B);
	dist2[A.first][A.second][B.first][B.second] = 0;
	int cnt_step = 1e9 + 100, cnt_diff = 1e9 + 100; // count more step, count number of step
	while(!qq.empty()){
		Node now = qq.front();
		qq.pop();
		if(abs(now.A.first - now.B.first) + abs(now.A.second - now.B.second) <= cnt_step){
			if(dist[now.A.first][now.A.second][now.B.first][now.B.second] < cnt_step){
				cnt_step = dist[now.A.first][now.A.second][now.B.first][now.B.second];
				cnt_diff = dist2[now.A.first][now.A.second][now.B.first][now.B.second];
			}
		}
		now_dist = dist2[now.A.first][now.A.second][now.B.first][now.B.second];
		for(int k=0; k<4; ++k){
			int aii = now.A.first + di[k], ajj = now.A.second + dj[k];
			int bii = now.B.first - di[k], bjj = now.B.second - dj[k];
			bool ok_A = inRange(aii, ajj), ok_B = inRange(bii, bjj);
			if(!ok_A && !ok_B){
				continue;
			}
			Add(ok_A ? make_pair(aii, ajj): now.A, ok_B ? make_pair(bii, bjj): now.B);
		}
	}
	cout << cnt_step << " " << cnt_diff;
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
