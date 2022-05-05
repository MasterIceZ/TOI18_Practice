/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_land
 * ALGO		: Brute Force
 * DATE		: 4 May 2022
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

int n, m;
double res = 1e9 + 100;

const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void rec(int last_i, int last_j, int cnt, double sum, vector<vector<double>> a){
	if(cnt == n * m){
		res = min(res, sum);
		return ;
	}
	auto nxt = a;
	for(int k=0; k<8; ++k){
		int ii = di[k] + last_i;
		int jj = dj[k] + last_j;
		if(ii < 1 || jj < 1 || ii > n || jj > m || !nxt[ii][jj]){
			continue;
		}
		nxt[ii][jj] += 0.1 * nxt[last_i][last_j];
	}
	nxt[last_i][last_j] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(nxt[i][j] != 0){
				rec(i, j, cnt + 1, sum + nxt[i][j], nxt);
			}
		}
	}
}

inline void solution(){
	cin >> n >> m;
	vector<vector<double>> a(n + 1, vector<double> (m + 1));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			rec(i, j, 1, a[i][j], a);
		}
	}
	cout << fixed << setprecision(2) << res;
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
