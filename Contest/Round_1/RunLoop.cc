/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Run Loop
 * ALGO		: Breadth First Search
 * DATE		: 15 May 2022
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
int dist[MxN][MxN];
queue<pair<int, int>> q;
vector<char> answer;

const char cv[] = {'D', 'L', 'R', 'U'};
const int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};

inline void solution(){
	int n, m, x;
	cin >> n >> m >> x;
	pair<int, int> stp;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'P'){
				stp = make_pair(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	q.emplace(stp);
	dist[stp.first][stp.second] = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first, jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m || dist[ii][jj] != -1 || a[ii][jj] == '#'){
				continue;
			}
			dist[ii][jj] = dist[now.first][now.second] + 1;
			q.emplace(ii, jj);
		}
	}
	int remain = x;
	answer.clear();
	while(remain--){
		for(int k=0; k<4; ++k){
			int ii = di[k] + stp.first, jj = dj[k] + stp.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m || dist[ii][jj] == -1 || dist[ii][jj] > remain){
				continue;
			}
			answer.emplace_back(cv[k]);
			stp = make_pair(ii, jj);	
			break;
		}
	}
	dbg(answer);
	if((int) answer.size() != x){
		cout << "Can\'t do";
	}
	else{
		for(auto x: answer){
			cout << x;
		}
	}
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
