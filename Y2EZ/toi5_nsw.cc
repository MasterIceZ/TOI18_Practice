/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_nsw
 * ALGO		: Brute Force
 * DATE		: 4 May 2022
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

struct decoder{
	string initial_key;
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	inline void roll_up(vector<int>& v, int t){
		while(t--){
			v.emplace_back(v[0]);
			v.erase(v.begin());
		}
	}
	inline void roll_down(vector<int>& v, int t){
		while(t--){
			v.insert(v.begin(), v.back());
			v.pop_back();
		}
	}
	inline void initial(string key){
		initial_key = key;
		roll_up(a, key[0] - '0' - 1);
		roll_up(b, key[1] - '0' - 1);
		roll_up(c, key[2] - '0' - 1);
	}
	inline int read(char x){
		int res = c[b[a[x - '0' - 1] - 1] - 1];
		roll_up(a, initial_key[0] - '0');
		roll_down(b, 1);
		roll_up(c, initial_key[2] - '0');
		return res;
	}
} machine;

inline void solution(){
	string key, w;
	cin >> key >> w;
	machine.initial(key);
	for(auto x: w){
		cout << machine.read(x);
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
