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

struct EVP{
	int idx, val;
	bool operator < (const EVP& o) const {
		if(idx != o.idx){
			return idx < o.idx;
		}
		return val < o.val;
	}
	EVP(int a, int b): idx(a), val(b) {}
};

const int MxN = 2020;
const int MxQ = 100010;
char a[MxN][MxN];
int n, m, q, hori[MxN][MxN], verti[MxN][MxN];
bool cluster[MxN][MxN];
vector<int> block_h[MxN], block_v[MxN];

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				block_h[i].emplace_back(j);
				block_v[j].emplace_back(i);
			}
		}
		block_h[i].emplace_back(m + 1);
	}
	for(int j=1; j<=m; ++j){
		block_v[j].emplace_back(n + 1);
	}
	cin >> q;
	int r, l, x, y, w, idx;
	while(q--){
		cin >> x >> y >> w;
		if(a[x][y] == '#'){
			continue;
		}
		cluster[x][y] ^= true;	
		// horizontal
		idx = lower_bound(block_h[x].begin(), block_h[x].end(), y) - block_h[x].begin();	
		if(idx == 0){
			l = max(1, y - w);
		}
		else{
			if(y - w < block_h[x][idx - 1]){
				l = block_h[x][idx - 1];
			}
			else{
				l = y - w;
			}
		}
		if(block_h[x][idx] == m + 1){
			r = min(m, y + w);
		}
		else{
			if(y + w > block_h[x][idx]){
				r = block_h[x][idx];
			}
			else{
				r = y + w;
			}
		}
		hori[x][l]++, hori[x][r + 1]--;
		// vertical
		idx = lower_bound(block_v[y].begin(), block_v[y].end(), x) - block_v[y].begin();	
		if(idx == 0){
			l = max(1, x - w);
		}
		else{
			if(x - w < block_v[y][idx - 1]){
				l = block_v[y][idx - 1];
			}
			else{
				l = x - w;
			}
		}
		if(block_v[y][idx] == n + 1){
			r = min(n, x + w);
		}
		else{
			dbg("K");
			if(x + w > block_v[y][idx]){
				r = block_v[y][idx];
				dbg("O");
			}
			else{
				r = x + w;
			}
		}
		dbg(idx);
		verti[l][y]++, verti[r + 1][y]--;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			hori[i][j] = hori[i][j] + hori[i][j - 1];
		}
	}
	for(int j=1; j<=m; ++j){
		for(int i=1; i<=n; ++i){
			verti[i][j] = verti[i][j] + verti[i - 1][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '#'){
				cout << "#";
			}
			else if(cluster[i][j] && (hori[i][j] + verti[i][j]) % 2 == 0){
				cout << "*";
			}
			else if(cluster[i][j]){
				cout << ".";
			}
			else if((hori[i][j] + verti[i][j]) % 2){
				cout << "*";
			}
			else{
				cout << ".";
			}
		}
		cout << "\n";
	}
	memset(cluster, false, sizeof cluster);
	memset(hori, 0, sizeof hori);
	memset(verti, 0, sizeof verti);
	for(int i=1; i<=n; ++i){
		block_h[i].clear();
	}
	for(int i=1; i<=m; ++i){
		block_v[i].clear();
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
