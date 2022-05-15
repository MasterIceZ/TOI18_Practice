/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Median
 * ALGO		: Heap
 * DATE		: 13 May 2022
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

priority_queue<double> maxx;
priority_queue<double, vector<double>, greater<double>> minn;

inline void solution(){
	int n;
	double x, med;
	scanf("%d %lf", &n, &x);
	printf("%.1lf\n", x);
	maxx.emplace(x);
	med = x;
	for(int i=2; i<=n; ++i){
		scanf("%lf", &x);
		if(maxx.size() > minn.size()){
			if(x > med){
				minn.emplace(x);
			}
			else{
				minn.emplace(maxx.top());
				maxx.pop();
				maxx.emplace(x);
			}
			med = (maxx.top() + minn.top()) / 2;
		}
		else if(minn.size() > maxx.size()){
			if(x < med){
				maxx.emplace(x);
			}
			else{
				maxx.emplace(minn.top());
				minn.pop();
				minn.emplace(x);
			}
			med = (maxx.top() + minn.top()) / 2;
		}
		else{
			if(x > med){
				minn.emplace(x);
				med = minn.top();
			}
			else{
				maxx.emplace(x);
				med = maxx.top();
			}
		}
		printf("%.1lf\n", med);
	}
	return ;
}

signed main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
//		cout << "\n";
		printf("\n");
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
