/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_map
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

struct Cell{
	int i, j, v;
	bool operator < (const Cell& o) const {
		if(i == o.i){
			return j < o.j;
		}
		return i > o.i;
	}
	Cell(int a, int b, int c): i(a), j(b), v(c) {}
	Cell(): i(0), j(0), v(0) {}
	operator int() const{
		return v;
	}
	int operator = (int a){
		return v = a;
	}
};

struct Node{
	int i, j, v;
	Node(int a, int b, int c): i(a), j(b), v(c) {}
	operator int() const{
		return v;
	}
};

const int MxN = 200 * 200 + 10;
Cell table[MxN];
vector<Node> adj[MxN];
bool visited[MxN];

inline void solution(){
	int u, v, n, m;
	char o;
	cin >> n >> m;
	int sz = n * m - 1;
	for(int i=0; i<=sz; ++i){
		table[i] = i;
	}
	for(int i=1; i<=sz; ++i){
		cin >> u >> o >> v;
		if(o == 'U'){
			adj[u].emplace_back(-1, 0, v);
			adj[v].emplace_back(1, 0, u);
		}
		else{
			adj[u].emplace_back(0, 1, v);
			adj[v].emplace_back(0, -1, u);
		}
	}
	table[0].i = 0, table[0].j = 0;
	queue<int> q;
	q.emplace(0);
	visited[0] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto x: adj[now]){
			if(visited[x]){
				continue;
			}
			visited[x] = true;
			table[x].i = table[now].i + x.i;
			table[x].j = table[now].j + x.j;
			q.emplace(x);
		}
	}
	sort(table, table + sz + 1);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cout << table[i * m + j] << " ";
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
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
