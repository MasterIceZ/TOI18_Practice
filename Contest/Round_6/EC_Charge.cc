/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Charge
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

set<vector<vector<int>>> st;
int n, m;

void rec(int state_i, int state_j, vector<vector<int>> v){
	if(state_i == n && state_j == m){
		st.emplace(v);
		cout << "---\n";
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
		return ;
	}
	if(v[state_i][state_j] == -1){
		v[state_i][state_j] = 0;
		rec(state_i + 1, state_j, v);
		v[state_i][state_j] = 1;
		rec(state_i, state_j + 1, v);
	}
	else{
		rec(state_i + 1, state_j, v);
		rec(state_i, state_j + 1, v);
	}
}

inline void solution(){
	int k;
	char opr;
	cin >> n >> m >> k;
	vector<vector<int>> v(n + 1, vector<int> (m + 1, -1));
	for(int i=1, x, y; i<=k; ++i){
		cin >> opr >> x >> y;
		v[x][y] = (opr == '+');
	}
	rec(1, 1, v);
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
