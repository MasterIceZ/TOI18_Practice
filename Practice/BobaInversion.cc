/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Boba Inversion
 * ALGO		: Dynamic Programming
 * DATE		: 12 May 2022
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


const int MxN = 5050;

struct Fenwick{
	int tree[MxN];
	inline void clear(){
		memset(tree, 0, sizeof tree);
	}
	inline void update(int idx){
		for(; idx<=5000; idx+=idx&-idx){
			tree[idx] += 1;
		}
	}
	inline int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

int dp[MxN][MxN], a[MxN];

inline void solution(){
	int n;
	cin >> n;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		c.emplace_back(a[i]);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
	}
	for(int r=n; r>=1; --r){
		for(int l=r; l>=1; --l){
			dp[l][r] = dp[l + 1][r] + fw.read(a[l] - 1);
			fw.update(a[l]);
		}
		fw.clear();
	}
	int q, l, r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << dp[l][r] << "\n";
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
