/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Scotch
 * ALGO		: Math
 * DATE		: 14 May 2022
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

ll cnt_a[3], cnt_b[3], cnt_ab[5];

inline void solution(){
	int n, a, b;
	cin >> n >> a >> b;
	for(int i=1; i<=n; ++i){
		int m_a = i % (a * 2), m_b =  i % (b * 2);
		if(m_a && m_a <= a){
			if(m_b && m_b <= b){
				cnt_a[0]++, cnt_b[0]++, cnt_ab[0]++;
			}
			else{
				cnt_a[0]++, cnt_b[1]++, cnt_ab[1]++;
			}
		}
		else{
			if(m_b && m_b <= b){
				cnt_a[1]++, cnt_b[0]++, cnt_ab[2]++;
			}
			else{
				cnt_a[1]++, cnt_b[1]++, cnt_ab[3]++;
			}
		}
	}
	ll answer = cnt_a[0] * cnt_a[0] + cnt_b[0] * cnt_b[0];
	answer += cnt_a[1] * cnt_a[1] + cnt_b[1] * cnt_b[1];
	answer -= cnt_ab[0] * cnt_ab[0];
	answer -= cnt_ab[1] * cnt_ab[1];
	answer -= cnt_ab[2] * cnt_ab[2];
	answer -= cnt_ab[3] * cnt_ab[3];
	cout << answer;
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
