/*
ID: lfshinj1
TASK: barn1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("barn1.in");
ofstream fout("barn1.out");

int main() {
	int m, s, c; fin >> m >> s >> c;
	int a[210], dp[210][55];
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= c; i ++) {
		fin >> a[i];
	}
	if (m >= c) { 
		fout << c << endl;
		return 0;
	}
	sort(a+1, a+c+1);
	a[0] = a[1];
	memset(dp, 0x1f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= c; j ++) {
			for (int k = 0; k < j; k ++) {
				dp[j][i] = min(dp[k][i-1] + a[j] - a[k+1] + 1, dp[j][i]);	
			}
		}
	}
	fout << dp[c][m] << endl;
	return 0;
}
