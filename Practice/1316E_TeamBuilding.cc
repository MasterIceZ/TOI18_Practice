/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Team Building
 * ALGO		: Dynamic Programming, Bitmasks
 * DATE		: 8 May 2022
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

const int MxN = 100010;
int dp[1 << 7], s[MxN][7];
pair<int, int> a[MxN];
bitset<MxN> used;

inline bool cmp(const pair<int, int> a, const pair<int, int> b){
	return a.first > b.first;
}

inline void solution(){
	int n, p, k;
	cin >> n >> p >> k;
	for(int i=0; i<n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<k; ++j){
			cin >> s[i][j];
		}
	}
	sort(a, a + n, cmp);
	memset(dp, 0x3f, sizeof dp);
	used[0] = true;
	dp[0] = 0;
	for(int i=0; i<n; ++i){
		int idx = a[i].second;
		for(int state=(1 << p)-1; state>=0; --state){
			if(used[state]){
				continue;
			}
			for(int j=0; j<p; ++j){
				if(!(state & (1 << j))){
					continue;
				}
				int last = dp[state ^ (1 << j)];
				dp[state ^ (1 << j)] = max(dp[state ^ (1 << j)], dp[state] + s[idx][j]);
				if(last != dp[state ^ (1 << j)]){
					used[state ^ (1 << j)] = true;
				}
			}
			int cnt = __builtin_popcount(state);
			if(i - cnt < k){
				int last = dp[state];
				dp[state] = max(dp[state], dp[state] + a[i].first);
				if(last != dp[state]){
					used[state] = true;
				}
			}
		}
	}
	cout << dp[(1 << p) - 1];
	
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
