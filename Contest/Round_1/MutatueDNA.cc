/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Mutate DNA
 * ALGO		: Dynamic Programming
 * DATE		: 15 May 2022
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
int ac[MxN], at[MxN], ca[MxN], ct[MxN], ta[MxN], tc[MxN];
int as[MxN], cs[MxN], ts[MxN], att[MxN], ctt[MxN], ttt[MxN];

inline void solution(){
	int answer, n, q, minn, _ac, _at, _ca, _ct, _ta, _tc, l, r;
	string s, t;
	cin >> n >> q >> s >> t;
	s = " " + s, t = " " + t;
	for(int i=1; i<=n; ++i){
		ac[i] = ac[i - 1] + (s[i] == 'A' && t[i] == 'C');
		at[i] = at[i - 1] + (s[i] == 'A' && t[i] == 'T');
		ca[i] = ca[i - 1] + (s[i] == 'C' && t[i] == 'A');
		ct[i] = ct[i - 1] + (s[i] == 'C' && t[i] == 'T');
		ta[i] = ta[i - 1] + (s[i] == 'T' && t[i] == 'A');
		tc[i] = tc[i - 1] + (s[i] == 'T' && t[i] == 'C');
		
		as[i] = as[i - 1] + (s[i] == 'A');
		cs[i] = cs[i - 1] + (s[i] == 'C');
		ts[i] = ts[i - 1] + (s[i] == 'T');

		att[i] = att[i - 1] + (t[i] == 'A');
		ctt[i] = ctt[i - 1] + (t[i] == 'C');
		ttt[i] = ttt[i - 1] + (t[i] == 'T');
	}
	while(q--){
		answer = 0;
		cin >> l >> r;
		r++;
		
		if(as[r] - as[l] != att[r] - att[l]){
			cout << -1 << "\n";
			continue;
		}
		if(cs[r] - cs[l] != ctt[r] - ctt[l]){
			cout << -1 << "\n";
			continue;
		}
		if(ts[r] - ts[l] != ttt[r] - ttt[l]){
			cout << -1 << "\n";
			continue;
		}

		_ac = ac[r] - ac[l];
		_ca = ca[r] - ca[l];
		dbg(_ac, _ca);
		minn = min(_ac, _ca);
		answer += minn; // swap c->a, a->c
		_ac -= minn, _ca -= minn;
		dbg(minn);

		_at = at[r] - at[l];
		_ta = ta[r] - ta[l];
		dbg(_at, _ta);
		minn = min(_at, _ta);
		answer += minn; // swap a->t, t->a
		_at -= minn, _ta -= minn;
		dbg(minn);

		_ct = ct[r] - ct[l];
		_tc = tc[r] - tc[l];
		dbg(_ct, _tc);
		minn = min(_ct, _tc);
		answer += minn; // swap c->t, t->c
		_ct -= minn, _tc -= minn;
		dbg(minn);

		dbg(answer);
		cout << answer + 2 * max(_tc, _ct) << "\n";
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
