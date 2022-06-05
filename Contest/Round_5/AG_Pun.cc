/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Pun
 * ALGO		: Dijkstra
 * DATE		: 27 May 2022
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
	int i, j;
	ll w;
	bool operator < (const Node &o) const {
		return w > o.w;
	}
	Node(int a, int b, ll c): i(a), j(b), w(c) {}
};

const int MxN = 1010;
ll a[MxN][MxN], dist[MxN][MxN];
int n, m;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	priority_queue<Node> pq;
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=m; ++i){
		pq.emplace(1, i, a[1][i]);
		dist[1][i] = a[1][i];
	}
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(int k=0; k<4; ++k){
			int ii = now.i + di[k], jj = now.j + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			int nxt = a[ii][jj] + now.w;
			if(dist[ii][jj] > nxt){
				pq.emplace(ii, jj, dist[ii][jj] = nxt);
			}
		}
	}
	cout << *min_element(dist[n] + 1, dist[n] + m + 1);
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
