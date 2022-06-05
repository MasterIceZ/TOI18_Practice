/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_GoodPerson
 * ALGO		: 
 * DATE		: 28 May 2022
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

int n;
const int MxN = 200020;
struct Fenwick{
	int tree[MxN];
	inline void clear(){
		memset(tree, 0, sizeof tree);
	}
	inline void update(int idx, int v){
		for(; idx<MxN; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	inline int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} ft;

int opr, a[MxN];

inline void solution(){
	cin >> n;
	int answer = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ft.clear();
	for(int i=1; i<=n; ++i){
		answer = answer + ft.read(n) - ft.read(a[i]);
		ft.update(a[i], 1);
	}
	cout << answer << " 0 0 0";
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int k;
	cin >> k;
	if(k != 1){
		exit(0);
	}
	cin >> opr;
	if(opr != 1){
		exit(0);
	}
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
