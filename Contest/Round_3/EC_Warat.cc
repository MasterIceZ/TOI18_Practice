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

const int MxN = 5050;
vector<int> adj[MxN];
int dist[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		for(int j=1, v; j<=x; ++j){
			cin >> v;
			adj[v].emplace_back(i);
		}
	}
	int answer = 1e9 + 100, current;
	queue<int> q;
	for(int i=1; i<=n; ++i){
		memset(dist, -1, sizeof dist);
		q.emplace(i);
		dist[i] = 1;
		current = 1;
		bool ok = true;
		while(!q.empty()){
			int now = q.front(); q.pop();
			for(auto x: adj[now]){
				if(dist[x] == -1){
					dist[x] = dist[now] + 1;
					current = current + dist[x];
					q.emplace(x);
				}
			}
		}
		for(int i=1; i<=n; ++i){
			if(dist[i] == -1){
				ok = false;
			}
		}
		dbg(current, i);
		if(ok){
			answer = min(answer, current);
		}
	}
	cout << answer;
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
