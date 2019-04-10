/*
ID: lfshinj1
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("beads.in");
ofstream fout("beads.out");

int l[440][2], r[440][2];
int main() {
	int n; fin >> n; 
	string s; fin >> s;
	
	if (n == 1) {
		fout << n << endl;
		return 0;
	}
	
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	int answer = -1;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'w') {
			int j = i; 
			while ((s[j] == 'w' || s[j] == 'b') && r[i][0] < n) { r[i][0] ++; j = (j+1)%n; }
			j = i;
			while ((s[j] == 'w' || s[j] == 'r') && r[i][1] < n) { r[i][1] ++; j = (j+1)%n; }
			j = i;
			while ((s[j] == 'w' || s[j] == 'b') && l[i][0] < n) { l[i][0] ++; j = (j-1+n)%n; }
			j = i;
			while ((s[j] == 'w' || s[j] == 'r') && l[i][1] < n) { l[i][1] ++; j = (j-1+n)%n; }
		} else if (s[i] == 'b') {
			int j = i; 
			while ((s[j] == 'w' || s[j] == s[i]) && r[i][0] < n) { r[i][0] ++; j = (j+1)%n; }
			j = i;
			while ((s[j] == 'w' || s[j] == s[i]) && l[i][0] < n) { l[i][0] ++; j = (j-1+n)%n; }
		} else {
			int j = i;
			while ((s[j] == 'w' || s[j] == s[i]) && r[i][1] < n) { r[i][1] ++; j = (j+1)%n; }
			j = i;
			while ((s[j] == 'w' || s[j] == s[i]) && l[i][1] < n) { l[i][1] ++; j = (j-1+n)%n; }
		}
	}

	for (int i = 0; i < n; i ++) 
		for (int j = 0; j < 2; j ++)
			for (int k = 0; k < 2; k ++) 
				answer = max(answer, r[i][j] + l[(i-1+n)%n][k]);

	fout << min(answer, n) << endl;
	return 0;
}
