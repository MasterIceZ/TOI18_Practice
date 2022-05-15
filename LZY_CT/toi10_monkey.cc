/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_monkey
 * ALGO		: Math
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

struct ST{
	int idx, hei;
	bool operator < (const ST& o) const {
		if(hei != o.hei){
			return hei < o.hei;
		}
		return idx < o.idx;
	}
	ST(int x, int y): idx(x), hei(y) {}
};

const int MxN = 200020;
int a[MxN];

inline void solution(){
	int n, m, k, p;
	cin >> m >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	vector<ST> st;
	for(int i=1, x, y; i<=k; ++i){
		cin >> x >> y;
		st.emplace_back(x, y);
	}
	sort(st.begin(), st.end());
	for(int i=k-1; i>=0; --i){
		swap(a[st[i].idx], a[st[i].idx + 1]);
	}
	dbg(to_string(a, 1, n));
	cin >> p;
	int answer_2 = 0, answer = a[p]; // base answer
	// use special stick
	for(int i=0; i<k; ++i){
		int le = st[i].idx, ri = st[i].idx + 1;
		if(p > 1 && i > 0 && st[i].hei == st[i - 1].hei && p - 1 == st[i - 1].idx + 1){
			answer_2 = max(answer_2, a[p - 2]);
		}
		else{
			answer_2 = max(answer_2, a[p - 1]);
		}
		answer_2 = max(answer_2, a[p + 1]);
		if(p == le || p == ri){
			p = le + ri - p;
		}
		swap(a[le], a[ri]);
	}
	dbg(answer_2);
	cout << max(answer_2, answer) << "\n";
	cout << (answer_2 > answer ? "USE": "NO");
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
