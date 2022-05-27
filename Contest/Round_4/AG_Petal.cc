/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Petal
 * ALGO		: 
 * DATE		: 26 May 2022
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

const int MxN = 1550;
priority_queue<ll> maxx;
priority_queue<ll, vector<ll>, greater<ll>> minn;
// mem[l][r] stores number answer in range [l, r]
// dp[state][i] stores if i in state group what will be the sum
ll dp[55][MxN], mem[MxN][MxN], a[MxN];

inline void solution(){
	int n, q, x;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		ll low = 0ll, high = 0ll, now;
		while(!minn.empty()){
			minn.pop();
		}
		while(!maxx.empty()){
			maxx.pop();
		}
		for(int j=i; j<=n; ++j){
			now = a[j];
			if(maxx.empty()){
				maxx.emplace(now);
				low = low + now;
			}
			else{
				if(now <= maxx.top()){
					if(maxx.size() == minn.size()){
						maxx.emplace(now);
						low = low + now;
					}
					else{
						high = high + maxx.top();
						low = low - maxx.top();
						minn.emplace(maxx.top());
						maxx.pop();
						low = low + now;
						maxx.emplace(now);
					}
				}
				else{
					if(minn.size() < maxx.size()){
						minn.emplace(now);
						high = high + now;
					}
					else if(now < minn.top()){
						maxx.emplace(now);
						low = low + now;
					}
					else{
						low = low + minn.top();
						high = high - minn.top();
						maxx.emplace(minn.top());
						minn.pop();
						high = high + now;
						minn.emplace(now);
					}

				}
			}
			// median stores at maxx.top()
			ll med = maxx.top();
			mem[i][j] = high - minn.size() * med + maxx.size() * med - low;
			dbg(mem[i][j]);
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int state=1; state<=50; ++state){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=i; ++j){
				dp[state][i] = min(dp[state][i], dp[state - 1][j - 1] + mem[j][i]);
			}
		}
	}
	while(q--){
		cin >> x;
		cout << dp[x][n];
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
