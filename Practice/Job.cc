/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Job
 * ALGO		:
 * DATE		: 22 May 2022
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

const int MxN = 25;
int a[MxN], dp[1 << MxN], stp[25], last[25], mirror[25];
vector<int> nx[17];

inline void solution(){
	int n, k;
	cin >> n;
	int ms = (1 << n) - 1, b;
//	for(int i=1; i<=ms; ++i){
//		bit[__builtin_popcount(i)].emplace_back(i);
//	}
	for(int i=1; i<=n; ++i){
		stp[i] = (1 << i) - 1;
		last[i] = (1 << i) - 1;
	}
	int mu = n >> 1;
	for(int i=1; i<=ms; ++i){
		int cnt = __builtin_popcount(i);
		if(cnt > mu){
			continue;
		}
		if(i == last[cnt]){
			continue;
		}
		nx[cnt].emplace_back(i - last[cnt]);
		last[cnt] = i;
	}
	for(int i=1; i<=mu; ++i){
		mirror[i] = i;
	}
	for(int i=mu+1, j=mu - 1 + (n % 2); i<n; ++i, --j){
		mirror[i] = j;
	}
//	for(int i=1; i<n; ++i){
//		if(mirror[i] != i){
//			reverse(nx[mirror[i]].begin(), nx[mirror[i]].end());
//		}
//		for(auto x: nx[mirror[i]]){
//			cout << x << " " ;
//		}
//		cout << "\n";
//	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1; i<=n; ++i){
		if(mirror[i] != i){
			reverse(nx[mirror[i]].begin(), nx[mirror[i]].end());
		}
		if(i == n){
			for(int j=0; j<n; ++j){
				cin >> k;
				b = 1 << j;
				dp[ms] = min(dp[ms], dp[ms ^ b] + k);
			}
		}
		else{
			for(int j=0; j<n; ++j){
				cin >> k;
				b = 1 << j;
				int st = stp[i];
				if(st & b){
					dp[st] = min(dp[st], dp[st ^ b] + k);
				}
				for(auto x: nx[mirror[i]]){
					st = st + x;
					if(st & b){
						dp[st] = min(dp[st], dp[st ^ b] + k);
					}
				}
			}
		}
	}
	cout << dp[ms];
//	memset(dp, 0x3f, sizeof dp);
//	dp[0] = 0;
//	for(int i=1; i<=n; ++i){
//		for(int j=0; j<n; ++j){
//			cin >> k;
//			b = 1 << j;
//			for(auto x: bit[i + 1]){
//				if(!(x & b)){
//					continue;
//				}
//				dp[x] = min(dp[x], dp[x ^ b] + k);
//			}
//		}
//	}
//	cout << dp[ms];
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
