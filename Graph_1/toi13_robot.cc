/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi13_robot
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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

const int MxN = 2020;
char a[MxN][MxN];
int dist[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	memset(dist, -1, sizeof dist);
	queue<pair<int, int>> q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'X'){
				q.emplace(i, j);
				dist[i][j] = 0;
			}
		}
	}
	int answer = 0, cnt = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || dist[ii][jj] != -1 || a[ii][jj] == 'W'){
				continue;
			}
			dist[ii][jj] = dist[now.first][now.second] + 1;
			q.emplace(ii, jj);
			if(a[ii][jj] == 'A'){
				answer += dist[ii][jj] * 2;
				cnt++;
			}
		}
	}
	cout << cnt << " " << answer;
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
