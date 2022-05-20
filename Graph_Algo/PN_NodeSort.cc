/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Node Sort
 * ALGO		: Topological Sort, Kahn's Algorithm
 * DATE		: 20 May 2022
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

const int MxN = 50050;
int in[MxN], n, m, u, v;
vector<int> adj[MxN], answer;
priority_queue<int, vector<int>, greater<int>> pq;

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[v].emplace_back(u);
		in[u]++;
	}
	for(int i=1; i<=n; ++i){
		if(in[i]){
			continue;
		}
		pq.emplace(i);
	}
	int t = -1;
	bool have = false;
	while(!pq.empty()){
		int now = pq.top();
		if(pq.size() >= 2){
			t = now;
			have = true;
		}
		pq.pop();
		answer.emplace_back(now);
		for(auto x: adj[now]){
			if(--in[x] == 0){
				pq.emplace(x);
			}
		}
	}
	dbg(answer);
	if((int) answer.size() != n){
		cout << "Never";
	}
	else if(have){
		cout << "Different";
		for(int i=0; i<n; ++i){
			if(answer[i] == t){
				swap(answer[i], answer[i + 1]);
				break;
			}
		}
		for(auto x: answer){
			cout << " " << x ;
		}
	}
	else{
		cout << "Same";
		for(auto x: answer){
			cout << " " << x ;
		}
	}
	answer.clear();
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	memset(in, 0, sizeof in);
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
