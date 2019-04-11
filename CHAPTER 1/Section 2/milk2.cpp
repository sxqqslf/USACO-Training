/*
ID: lfshinj
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");

int st[5050], ed[5050], r[5005];

int cmp(int x, int y) {
	return st[x] < st[y] || st[x] == st[y] && ed[x] <= ed[y];
}

int main() {
	int n; fin >> n;
	for (int i = 0; i < n; i ++) {
		fin >> st[i] >> ed[i];
		r[i] = i;
	}
	sort(r, r + n, cmp);

	int s = st[r[0]], e = ed[r[0]];
	int ans = e - s, idle = 0;
	for (int i = 1; i < n; i ++) {
		if (st[r[i]] > e) {
			ans = max(ans, e - s);
			idle = max(idle, st[r[i]] - e);
			s = st[r[i]]; e = ed[r[i]];
		} else {
			e = max(e, ed[r[i]]);
		}
		ans = max(ans, e - s);
	}
	fout << ans << ' ' << idle << endl;
	return 0;
}

