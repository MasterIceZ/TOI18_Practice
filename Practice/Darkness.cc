/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Darkness
 * ALGO		: Dijkstra
 * DATE		: 22 May 2022
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
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

const int MxN = 2022;
pair<int, int> village[MxN];
char x, s[10010];
int dist[MxN];

inline int get_dist(pair<int, int> a, pair<int, int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

inline void solution(){
	int n, m, k, it = 0;
	scanf("%d %d %d", &n, &m, &k);
	pair<int, int> b;
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=n; ++i){
		scanf(" %s", (s + 1));
		for(int j=1; j<=m; ++j){
			x = s[j];
			if(x == 'A'){
				village[0] = make_pair(i, j);
			}
			else if(x == 'X'){
				village[++it] = make_pair(i, j);
			}
			else if(x == 'B'){
				b = make_pair(i, j);
			}
		}
	}
	village[++it] = b;
	if(get_dist(village[0], village[it]) <= k){
		printf("%d", get_dist(village[0], village[it]));
		return ;
	}
	priority_queue<Node> pq;
	dist[0] = 0;
	pq.emplace(0, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(int i=0; i<=it; ++i){
			if(get_dist(village[now.v], village[i]) > k){
				continue;
			}
			int nxt = get_dist(village[now.v], village[i]) + now.w;
			if(dist[i] > nxt){
				pq.emplace(i, dist[i] = nxt);
			}
		}
	}
	printf("%d", (dist[it] >= 1e9 + 100? -1: dist[it]));
	return ;
}

signed main(){
	int q = 1;
	while(q--){
		solution();
		printf("\n");
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
