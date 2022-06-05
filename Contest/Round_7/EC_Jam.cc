/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Jam
 * ALGO		: 
 * DATE		: 29 May 2022
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
	int i, j, w, face;
	bool operator < (const Node& o) const {
		return w < o.w;
	}
	Node(int a, int b, int c, int d): i(a), j(b), w(c), face(d) {}
};

const int MxN = 1010;
char a[MxN][MxN];
int qs[MxN][MxN], l[MxN], r[MxN];

inline void solution(){
	int n, m, tp = -1;
	cin >> n >> m;
	memset(l, 0x3f, sizeof l);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(tp == -1){
				tp = i;
			}
			qs[i][j] = qs[i][j - 1] + (a[i][j] == 'J');
			if(a[i][j] == 'J'){
				l[i] = min(l[i], j);
			}
			else{
				r[i] = max(r[i], j);
			}
		}
	}
	// pos -> (n, 1)
	int face = 1, ps = 1, cnt = 0;
	for(int i=n; i>=tp; --i){
		if(qs[i][n] != 0){
			if(face == 1){
				cnt += r[i] - ps + 1;
				ps = r[i];
			}
			else{
				cnt += ps - l[i] + 1;
				ps = l[i];
			}
		}
		face ^= 1;
	}
	cout << cnt;
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
