/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Table
 * ALGO		: Dijkstra
 * DATE		: 19 May 2022
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
	int i, j, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c): i(a), j(b), w(c) {}
};

const int MxN = 33;
char a[MxN][MxN];
int n, x, y, dist[MxN][MxN];
priority_queue<Node> pq;
bitset<MxN> visited[MxN];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline int dijkstra(int i, int j){
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	pq.emplace(i, j, 0);
	dist[i][j] = 0;
	visited[i][j] = true;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i, jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			int nxt = now.w + (a[ii][jj] == a[now.i][now.j] ? x: y);
			if(dist[ii][jj] > nxt){
				pq.emplace(ii, jj, dist[ii][jj] = nxt);
				visited[ii][jj] = true;
			}
		}
	}
	int res = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(!visited[i][j]){
				continue;
			}
			res = max(res, dist[i][j]);
		}
	}
	return res;
}

inline void solution(){
	cin >> n >> x >> y;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			answer = max(answer, dijkstra(i, j));
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
