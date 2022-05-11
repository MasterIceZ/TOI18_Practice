/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_disaster
 * ALGO		: Depth First Search
 * DATE		: 7 May 2022
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

int deg[33], n;
vector<pair<int, int>> adj[33];
bitset<333> visited;
vector<int> answer;

void dfs(int u){
	if((int) answer.size() == 1 + n){
		for(auto x: answer){
			cout << (char) (x + 'A') << " ";
		}
		exit(0);
	}
	for(auto x: adj[u]){
		if(visited[x.second]){
			continue;
		}
		answer.emplace_back(x.first);
		visited[x.second] = true;
		dfs(x.first);
		answer.pop_back();
		visited[x.second] = false;
	}
}

inline void solution(){
	string s;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> s;
		int u = s[0] - 'A', v =  s[1] - 'A';
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
		deg[u]++, deg[v]++;
	}
	for(int i=0; i<26; ++i){
		sort(adj[i].begin(), adj[i].end());
	}
	int stp = -1, stp2 = 1e9;
	for(int i=0; i<26; ++i){
		if(deg[i] % 2 && stp == -1){
			stp = i;
		}
		else if(deg[i]){
			stp2 = min(stp2, i);
		}
	}
	answer.emplace_back(stp == -1 ? stp2: stp);
	dfs(stp == -1 ? stp2: stp);
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
