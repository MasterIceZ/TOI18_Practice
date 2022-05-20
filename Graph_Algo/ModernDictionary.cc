/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Modern Dictionary
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

const int MxN = 33;
string s, t;
vector<int> adj[MxN];
int in[MxN];
set<int> st;
bitset<MxN> used;

inline void insert_set(string s){
	for(auto x: s){
		st.emplace(x - 'a');
	}
	return ;
}

inline void solution(){
	int n;
	cin >> n >> t;
	insert_set(t);
	for(int i=2; i<=n; ++i){
		cin >> s;
		int sz = min(s.size(), t.size());
		for(int j=0; j<sz; ++j){
			if(s[j] == t[j]){
				continue;
			}
			int u = t[j] - 'a', v = s[j] - 'a';
			adj[u].emplace_back(v);
			in[v]++;
			used[u] = used[v] = true;
			break;
		}
		t = s;
		insert_set(t);
	}
	queue<int> q;
	for(auto x: st){
		if(in[x] == 0 && used[x]){
			dbg((char) (x + 'a'));
			q.emplace(x);
		}
	}
	vector<char> dict;
	while(!q.empty()){
		if(q.size() != 1){
			cout << "?";
			return ;
		}
		int now = q.front(); q.pop();
		dict.emplace_back(now + 'a');
		for(auto x: adj[now]){
			if(--in[x] == 0){
				q.emplace(x);
			}
		}
	}
	for(int i=0; i<26; ++i){
		if(in[i] <= 0){
			continue;
		}
		cout << "!";
		return ;
	}	
	if(dict.size() != st.size()){
		cout << "?";
	}
	else{
		for(auto x: dict){
			cout << (char) x;
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
