/*
ID: lfshinj1
TASK: milk
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");

int p[5050], a[5050], r[5050];

bool cmp(int x, int y) {
	return p[x] < p[y];
}

int main() {
	int n, m; fin >> n >> m;
	for (int i = 0; i < m; i ++) {
		fin >> p[i] >> a[i];
		r[i] = i;
	}
	sort(r, r + m, cmp);
	long long cost = 0;
	for (int i = 0; i < m; i ++) {
		if (n > 0) {
			cost += min(n, a[r[i]]) * 1LL * p[r[i]];
			n -= a[r[i]];
		}
	}
	fout << cost << endl;
	return 0;
}
