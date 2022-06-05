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

const int MxN = 1010;
char a[MxN][MxN];
int dist[MxN][MxN], dp[MxN][MxN][5], DP[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '#'){
				continue;
			}
			dp[i][j][0] = 1 + min(dp[i - 1][j][0], dp[i][j - 1][0]);
		}
		for(int j=m; j>=1; --j){
			if(a[i][j] == '#'){
				continue;
			}
			dp[i][j][1] = 1 + min(dp[i - 1][j][1], dp[i][j + 1][1]);
		}
	}
	for(int i=n; i>=1; --i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '#'){
				continue;
			}
			dp[i][j][2] = 1 + min(dp[i + 1][j][2], dp[i][j - 1][2]);
		}
		for(int j=m; j>=1; --j){
			if(a[i][j] == '#'){
				continue;
			}
			dp[i][j][3] = 1 + min(dp[i + 1][j][3], dp[i][j + 1][3]);
		}
	}
	int maxx = 0;
	pair<int, int> ps;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			DP[i][j] = min({dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]});
			if(DP[i][j] > maxx){
				ps = make_pair(i, j);
				maxx = DP[i][j];
			}
		}
	}
	queue<pair<int, int>> q;
	q.emplace(ps);
	const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
	memset(dist, -1, sizeof dist);
	dist[ps.first][ps.second] = 1;
	while(!q.empty()){
		auto now = q.front(); q.pop();
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || dist[ii][jj] != -1){
				continue;
			}

			dist[ii][jj] = dist[now.first][now.second] + 1;
			q.emplace(ii, jj);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(dist[i][j] <= maxx){
				cout << "x";
			}
			else{
				cout << a[i][j];
			}
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
