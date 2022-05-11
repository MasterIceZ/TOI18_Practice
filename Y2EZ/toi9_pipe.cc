/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_pipe
 * ALGO		: Brute Force
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

const int MxN = 330;
int n, m, cnt = 0;
int a[MxN][MxN];
vector<int> v;

void dfs(int i, int j, int last_i, int last_j){
	if(a[last_i][last_j] == 31){
		if(i != last_i){
			a[last_i][last_j] = 22;
		}
		else{
			a[last_i][last_j] = 21;
		}
	}
	else{
		a[last_i][last_j] = 0;
	}
	if(i < 1 || j < 1 || i > n || j > m){
		v.emplace_back(cnt);
		return ;
	}
	cnt++;
	if(a[i][j] == 11){
		if(j == last_j){
			dfs(i, j - 1, i, j);
		}
		else{
			dfs(i - 1, j, i, j);
		}
	}
	else if(a[i][j] == 12){
		if(i == last_i){
			dfs(i - 1, j, i, j);
		}
		else{
			dfs(i, j + 1, i, j);
		}
	}
	else if(a[i][j] == 13){
		if(j == last_j){
			dfs(i, j - 1, i, j);
		}
		else{
			dfs(i + 1, j, i, j);
		}
	}
	else if(a[i][j] == 14){
		if(i == last_i){
			dfs(i + 1, j, i, j);
		}
		else{
			dfs(i, j + 1, i, j);
		}
	}
	else if(a[i][j] == 31){
		if(i == last_i){
			if(j > last_j){
				dfs(i, j + 1, i, j);
			}
			else{
				dfs(i, j - 1, i, j);
			}
		}
		else{
			if(i > last_i){
				dfs(i + 1, j, i, j);
			}
			else{
				dfs(i - 1, j, i, j);
			}
		}
	}
	else if(a[i][j] == 21){
		if(i > last_i){
			dfs(i + 1, j, i, j);
		}
		else{
			dfs(i - 1, j, i, j);
		}
	}
	else if(a[i][j] == 22){
		if(j > last_j){
			dfs(i, j + 1, i, j);
		}
		else{
			dfs(i, j - 1, i, j);
		}
	}
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int j=1; j<=m; ++j){
		if(a[1][j] == 11 || a[1][j] == 12 || a[1][j] == 21 || a[1][j] == 31){
			cnt = 0;
			dfs(1, j, 0, j);
		}
	}
	for(int j=1; j<=m; ++j){
		if(a[n][j] == 13 || a[n][j] == 14 || a[n][j] == 21 || a[n][j] == 31){
			cnt = 0;
			dfs(n, j, n + 1, j);
		}
	}
	for(int i=1; i<=n; ++i){
		if(a[i][1] == 11 || a[i][1] == 13 || a[i][1] == 22 || a[i][1] == 31){
			cnt = 0;
			dfs(i, 1, i, 0);
		}
	}
	for(int i=1; i<=n; ++i){
		if(a[i][m] == 12 || a[i][m] == 14 || a[i][m] == 22 || a[i][m] == 31){
			cnt = 0;
			dfs(i, m, i, m + 1);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for(auto x: v){
		cout << x << " ";
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
