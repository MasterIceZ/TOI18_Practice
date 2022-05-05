/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: COI_Board Game !
 * ALGO		: Breadth First Search
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
	pair<int, int> position;
	int j, b, p;
	Node(pair<int, int> x, int z, int n, int m): position(x), j(z), b(n), p(m) {}
};

const int MxN = 550;
char a[MxN][MxN];
int dist[MxN][MxN][2][2][2];

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
	memset(dist, 0x3f, sizeof dist);
	dist[stp.first][stp.second][0][0][0] = 0;
	queue<Node> q;
	q.emplace(stp, 0, 0, 0);
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		int now_dist = dist[now.position.first][now.position.second][now.j][now.b][now.p];
		dbg(now.position, now.j, now.b, now.p);
		if(now.position == edp){
			cout << now_dist;
			return ;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.position.first;
			int jj = dj[k] + now.position.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == '#'){
				continue;
			}
			if((a[ii][jj] == 'J' && now.j == 0) || (a[ii][jj] == 'B' && now.b == 0) || (a[ii][jj] == 'P' && now.p == 0)){
				continue;
			}
			int nxt_j = ((a[ii][jj] == 'j') | now.j);
			int nxt_b = ((a[ii][jj] == 'b') | now.b);
			int nxt_p = ((a[ii][jj] == 'p') | now.p);
			if(dist[ii][jj][nxt_j][nxt_b][nxt_p] > now_dist + 1){
				q.emplace(make_pair(ii, jj), nxt_j, nxt_b, nxt_p);
				dist[ii][jj][nxt_j][nxt_b][nxt_p] = now_dist + 1;
			}
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
