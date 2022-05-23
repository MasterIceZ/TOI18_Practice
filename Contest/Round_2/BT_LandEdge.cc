/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Land Edge
 * ALGO		: Dynamic Programming
 * DATE		: 21 May 2022
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
ll qs[MxN][MxN], a[MxN][MxN];

inline ll get_sum(int a, int b, int c, int d){
	if(c < a || d < b){
		return 0ll;
	}
	return qs[c][d] + qs[a][b] - qs[c][b] - qs[a][d];
}

inline ll get_rec(int a, int b, int c, int d){
	return get_sum(a - 1, b - 1, c, d);
}

inline ll get_sq(int a, int b, int c, int d){
	return get_rec(a, b, c, d) - get_rec(a + 1, b + 1, c - 1, d - 1);
}

pair<int, int> x, y;

inline void solution(){
	int n, q, o, k, a, b, c, d;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> qs[i][j];
			::a[i][j] = qs[i][j];
			qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
		}
	}
	cin >> q;
	while(q--){
		cin >> o;
		o--;
		if(!o){
			cin >> k >> a >> b;
			cout << get_sq(a, b, a + k - 1, b + k - 1) << "\n"; 
		}
		else{
			cin >> k >> a >> b >> c >> d;
			int all = get_sq(a, b, a + k - 1, b + k - 1) + get_sq(c, d, c + k - 1, d + k - 1);
			x = make_pair(a, b), y = make_pair(c, d);
			if(x == y){
			    cout << get_sq(a, b, a + k - 1, b + k - 1) << "\n";
				continue;
			}
			if(x > y){
			    swap(x, y);
			}
			bool ok = true;
			if(x.first <= y.first && y.first <= x.first + k - 1){
				ok = false;
			}
			if(x.first <= y.first + k - 1 && y.first + k - 1 <= x.first + k - 1){
				ok = false;
			}
			if(y.first <= x.first && x.first <= y.first + k - 1){
				ok = false;
			}
			if(y.first <= x.first + k - 1 && x.first + k - 1 <= y.first + k - 1){
				ok = false;
			}
			if(ok){
				dbg("OK");
				cout << all << "\n";
				continue;
			}
			dbg(all);
			if(x.first + k - 1 == y.first && y.second <= x.second && x.second <= y.second + k - 1){
				all -= get_rec(y.first, x.second, y.first, y.second + k - 1);
				dbg("1");
				dbg(y.first, x.second, y.first, y.second + k - 1);
				dbg(get_rec(y.first, x.second, y.first, y.second + k - 1));
			}	
			else if(x.first + k - 1 == y.first){
				all -= get_rec(y.first, y.second, x.first + k - 1, x.second + k - 1);
				dbg("2");
				dbg(y.first, y.second, x.first + k - 1, x.second + k - 1);
				dbg(get_rec(y.first, y.second, x.first + k - 1, x.second + k - 1));
			}
			else if(x.first < y.first && x.second >= y.second && x.second <= y.second + k - 1){
				all -= get_rec(y.first, x.second, x.first + k - 1, y.second + k - 1);
				all += get_rec(y.first + 1, x.second + 1, x.first + k - 2, y.second + k - 2);
				all += ::a[y.first][x.second] + ::a[x.first + k - 1][y.second + k - 1];
				dbg("3");
				dbg(y.first, x.second, x.first + k - 1, y.second + k - 1);
				dbg(get_rec(y.first, x.second, x.first + k - 1, y.second + k - 1));
			}
			else if(x.first < y.first && x.second <= y.second && x.second <= y.second + k - 1){
				all -= get_rec(y.first, y.second, x.first + k - 1, x.second + k - 1);
				all += get_rec(y.first + 1, y.second + 1, x.first + k - 2, x.second + k - 2);
				all += ::a[y.first][x.second + k - 1] + ::a[x.first + k - 1][y.second];
				dbg("4");
				dbg(y.first, y.second, x.first + k - 1, x.second + k - 1);
				dbg(get_rec(y.first, y.second, x.first + k - 1, x.second + k - 1));
			}
			else if(x.first == y.first && x.second != y.second){
				all = get_sq(x.first, x.second, y.first + k - 1, y.second + k - 1);
			}
			else if(x.first != y.first && x.second == y.second){
				all = get_sq(x.first, x.second, y.first + k - 1, y.second + k - 1);
			}
			cout << all << "\n";
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
