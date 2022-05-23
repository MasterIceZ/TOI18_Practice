/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Tension7
 * ALGO		: Dynamic Programming 
 * DATE		: 21 May 2022
 * */

#include <stdio.h>

const int MxN = 660;
int dp[MxN][MxN], qs[MxN];

inline int min(int a, int b){
	return (a > b ? b: a);
}

inline int max(int a, int b){
	return (a < b? b: a);
}

int main(){
	int q = 1;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			scanf("%d", &qs[i]);
			qs[i] += qs[i - 1];
		}
		for(int sz=1; sz<n; ++sz){
			for(int i=1; i+sz<=n; ++i){
				int j = i + sz;
				dp[i][j] = 0;
				for(int k=i; k<j; ++k){
					int l = qs[k] - qs[i - 1], r = qs[j] - qs[k];
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + max(l, r) + (min(l, r) << 1));
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
