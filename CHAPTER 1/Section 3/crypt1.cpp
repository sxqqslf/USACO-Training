/*
ID: lfshinj1
TASK: crypt1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

int n, p[20], record[20];

bool valid(int x, int p) {
	while (x) {
		if (!record[x%10]) return 0;	
		x = x/10; p --;
	}
	return p == 0;
}

int main() {
	fin >> n;
	memset(record, 0, sizeof(record));
	for (int i = 0; i < n; i ++) {
		fin >> p[i];
		record[p[i]] = 1;
	}

	int cnt = 0;
	for (int a = 0; a < n; a ++)
		for (int b = 0; b < n; b ++)
			for (int c = 0; c < n; c ++) 
				for (int d = 0; d < n; d ++)
					for (int e = 0; e < n; e ++) {
						int x = p[a]*100 + p[b]*10 + p[c];
						int y = p[d] * 10 + p[e];
						int p1 = x * p[e], p2 = x * p[d];
						if (valid(p1, 3) && valid(p2, 3) && valid(x*y, 4)) {
							cnt ++;
						}
					}
	fout << cnt << endl;
	return 0;
}
