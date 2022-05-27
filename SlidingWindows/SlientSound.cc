/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Slient Sound
 * ALGO		: Sliding Windows
 * DATE		: 25 May 2022
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

const int MxN = 1000010;
int n, m, c, a[MxN];
deque<pair<int, int>> minn, maxx;

inline void solution(){
	cin >> n >> m >> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	bool ok = false;
	for(int i=1; i<=n; ++i){
		while(!minn.empty() && minn.front().first <= i - m){
			minn.pop_front();
		}
		while(!maxx.empty() && maxx.front().first <= i - m){
			maxx.pop_front();
		}
		while(!minn.empty() && minn.back().second >= a[i]){
			minn.pop_back();
		}
		while(!maxx.empty() && maxx.back().second <= a[i]){
			maxx.pop_back();
		}
		minn.emplace_back(i, a[i]);
		maxx.emplace_back(i, a[i]);
		dbg(maxx.front().first, minn.front().first);
		if(i >= m && maxx.front().second - minn.front().second <= c){
			cout << i - m + 1 << "\n";
			ok = true;
		}
	}
	if(!ok){
		cout << "NONE";
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
