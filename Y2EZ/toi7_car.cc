/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_car
 * ALGO		: Dynamic Programming
 * DATE		: 5 May 2022
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

const int MxN = 110;
int a[MxN][MxN];
bool dp[MxN][MxN];

inline void solution(){
	int m, s, n;
	cin >> m >> s >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	dp[0][s] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j]){
				continue;
			}
			dp[i][j] = (dp[i - 1][j - 1] | dp[i - 1][j] | dp[i - 1][j + 1]);
		}
	}
	int now = -1;
	for(int i=1; i<=m; ++i){
		if(dp[n][i]){
			now = i;
			break;
		}
	}
	stack<int> answer;	
	for(int i=n; i>=1; --i){
		if(dp[i - 1][now - 1]){
			answer.emplace(2);
			now--;
		}
		else if(dp[i - 1][now]){
			answer.emplace(3);
		}
		else{
			answer.emplace(1);
			now++;
		}
	}
	while(!answer .empty()){
		cout << answer.top() << "\n";
		answer.pop();
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
