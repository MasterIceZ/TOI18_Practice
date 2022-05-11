/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: COI_Board Game !
 * ALGO		: Breadth First Search, Bitmasks
 * DATE		: 6 May 2022
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

struct Node{
	int i, j, bit;
	Node(int a, int b, int c): i(a), j(b), bit(c) {}
};

const int MxN = 550;
char a[MxN][MxN];
int dist[MxN][MxN][1 << 3];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void solution(){
	int n, m;
	cin >> n >> m;
	pair<int, int> stp, edp;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'S'){
				stp = make_pair(i, j);	
			}
			if(a[i][j] == 'E'){
				edp = make_pair(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	queue<Node> q;
	q.emplace(stp.first, stp.second, 0);
	dist[stp.first][stp.second][0] = 0;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		int now_dist = dist[now.i][now.j][now.bit];
		if(make_pair(now.i, now.j) == edp){
			cout << now_dist;
			return ;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '#' || (a[ii][jj] == 'J' && !(now.bit & 1)) || (a[ii][jj] == 'B' && !(now.bit & 2)) || (a[ii][jj] == 'P' && !(now.bit & 4))){
				continue;
			}
			int nxt_bit = now.bit;
			nxt_bit |= (a[ii][jj] == 'j' ? 1: 0);
			nxt_bit |= (a[ii][jj] == 'b' ? 2: 0);
			nxt_bit |= (a[ii][jj] == 'p' ? 4: 0);
			if(dist[ii][jj][nxt_bit] != -1){
				continue;
			}
			dist[ii][jj][nxt_bit] = now_dist + 1;
			q.emplace(ii, jj, nxt_bit);
		}
	}
	cout << "-1";
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
