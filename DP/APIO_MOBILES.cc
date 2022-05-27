/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
int child[MxN][3], dp[MxN], balance[MxN], cnt[MxN];
bool ok = true;
bitset<MxN> visited;

void dfs(int u){
	if(visited[u]){
		ok = false;
		return ;
	}
	int cnt_l = 0, cnt_r = 0;
	if(child[u][0] != -1){
		dfs(child[u][0]);
	}
	else{
		cnt_l++;
	}
	if(child[u][1] != -1){
		dfs(child[u][1]);
	}
	else{
		cnt_r++;
	}
	visited[u] = true;

	int left_balance = 0, right_balance = 0;
	int left_cnt = cnt_l, right_cnt = cnt_r;
	if(child[u][0] != -1){
		dp[u] = dp[u] + dp[child[u][0]];
		left_balance = balance[child[u][0]];
		left_cnt = cnt[child[u][0]];
	}
	if(child[u][1] != -1){
		dp[u] = dp[u] + dp[child[u][1]];
		right_balance = balance[child[u][1]];
		right_cnt = cnt[child[u][1]];
	}
	if(left_balance < right_balance){
		dbg(u, "balancing");
		dp[u] = dp[u] + 1;
	}
	else if(left_cnt < right_cnt){
		dbg(u, "r > l");
		dp[u] = dp[u] + 1;
	}
	
	dbg(u, left_cnt, right_cnt);
	if(abs(left_cnt - right_cnt) > 1){
		ok = false;
	}
	cnt[u] = left_cnt + right_cnt;
	balance[u] = max(left_balance, right_balance) + 1;
	return ;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1, x, y; i<=n; ++i){
		cin >> x >> y;
		child[i][0] = x, child[i][1] = y;
		if(x == -1 && y == -1){
			balance[i] = 1;
		}
	}
	dfs(1);
	if(!ok){
		cout << -1;
	}
	else{
		cout << dp[1];
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
