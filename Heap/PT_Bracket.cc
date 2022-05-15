/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Bracket
 * ALGO		: Heap, Greedy
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

inline void solution(){
	string s;
	cin >> s;
	priority_queue<ll> pq;
	ll res = 0, a, b;
	int balance = 0;
	bool ok = true;
	for(auto x: s){
		if(!ok){
			continue;
		}
		if(x == '('){
			balance++;
		}
		else if(x == ')'){
			balance--;
		}
		else{
			cin >> a >> b;
			pq.emplace(b - a);
			res += b;
			balance--;
		}
		if(balance < 0){
			if(pq.empty()){
				ok = false;
			}
			else{
				res -= pq.top();
				pq.pop();
				balance += 2;
			}
		}
	}
	cout << ((ok && !balance) ? res: -1);
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
