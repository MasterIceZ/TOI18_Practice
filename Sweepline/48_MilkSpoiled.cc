/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Milk Spoiled
 * ALGO		: Sweepline
 * DATE		: 9 May 2022
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

int x, y, z;
vector<pair<int, int>> line;

inline void solution(){
	line.clear();
	int n, j;
	cin >> n >> x >> y >> z;
	for(int i=1, l, r; i<=n; ++i){
		cin >> l >> r;
		line.emplace_back(l, 1);
		line.emplace_back(r + 1, -1);
	}
	line.emplace_back(0, 0);
	sort(line.begin(), line.end());
	int answer = 0, cnt_x = n, cnt_y = 0, cnt_z = 0;
	for(int i=1; i<(int) line.size(); i=j){
		for(j=i; j<(int) line.size() && line[i].first == line[j].first; ++j){
			if(line[j].second == 1){
				cnt_x--, cnt_y++;
			}
			else if(line[j].second == -1){
				cnt_y--, cnt_z++;
			}
		}
		answer = max(answer, cnt_x * x + cnt_y * y + cnt_z * z);
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
