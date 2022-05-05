/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi4_school
 * ALGO		: Dynamic Programming, Depth First Search
 * DATE		: 5 May 2022
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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

const int MxN = 66;
int n, m;
char a[MxN][MxN];
bool visited[MxN][MxN];
int dp[MxN][MxN];

void dfs(int i, int j){
	visited[i][j] = true;
	for(int k=0; k<4; ++k){
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > n || jj > m || visited[ii][jj] || a[ii][jj] != 'P'){
			continue;
		}
		dfs(ii, jj);
	}
}

int cnt_pound(int a, int b, int c, int d){
	int cnt = 0;
	memset(visited, false, sizeof visited);
	for(int i=a; i<=c; ++i){
		for(int j=b; j<=d; ++j){
			if(::a[i][j] == 'S' || visited[i][j]){
				continue;
			}
			dfs(i, j);
			cnt++;
		}
	}
	return cnt;
}

inline void solution(){
	cin >> m >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i][j] == 'T');
		}
	}
	int max_size = min(n, m);
	bool can = false;
	for(int k=max_size; k>=1; --k){
		int minn = 1e9 + 100;
		for(int i=k; i<=n; ++i){
			for(int j=k; j<=m; ++j){
				int tree_cnt = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
				if(tree_cnt != 0){
					continue;
				}
				can = true;
				minn = min(minn, cnt_pound(i - k + 1, j - k + 1, i, j));
			}
		}
		if(can){
			cout << k * k << " " << minn;
			return ;
		}
	}
	cout << "0 0";
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
