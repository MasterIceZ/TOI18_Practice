/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_sewer
 * ALGO		: Breadth First Search
 * DATE		: 5 May 2022
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

const int MxN = 110;
char x;
vector<pair<int, int>> adj[MxN][MxN];
int dist[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> x;
			if(x == 'B' || x == 'R'){
				adj[i][j].emplace_back(i, j + 1);
				adj[i][j + 1].emplace_back(i, j);
			}
			if(x == 'B' || x == 'D'){
				adj[i][j].emplace_back(i + 1, j);
				adj[i + 1][j].emplace_back(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	dist[1][1] = 1;
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(auto x: adj[now.first][now.second]){
			int nxt_dist = dist[now.first][now.second] + 1;
			if(dist[x.first][x.second] == -1){
				q.emplace(x);
				dist[x.first][x.second] = nxt_dist;
			}
			else{
				if(dist[x.first][x.second] == nxt_dist){
					cout << nxt_dist << "\n" << x.first << " " << x.second ;
					return ;
				}
			}
		}
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
