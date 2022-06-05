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

struct Node{
	int i, j, w;
	bool operator < (const Node& o) const {
		return w < o.w;
	}
	Node(int a, int b, int c): i(a), j(b), w(c) {}
};

const int MxN = 110;
int n, m, h[MxN][MxN];
priority_queue<Node> pq;
int dist[MxN][MxN];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> h[i][j];
			dist[i][j] = 1;
			pq.emplace(i, j, 1);
		}
	}
	int maxx = 0;
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		if(dist[now.i][now.j] != now.w){
			continue;
		}
		maxx = max(maxx, now.w);
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i, jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			int nxt = now.w + 1;
			dbg(now.i, now.j, ii, jj);
			if(h[ii][jj] > h[now.i][now.j] && dist[ii][jj] < nxt){
				pq.emplace(ii, jj, dist[ii][jj] = nxt);
			}
		}
	}
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=m; ++j){
//			cout << dist[i][j];
//		}
//		cout << "\n";
//	}
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
