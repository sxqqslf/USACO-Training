/*
ID: lfshinj1
TASK: combo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("combo.in");
ofstream fout("combo.out");

int n;
int dup(int x, int y) {
	int vis[110] = {0}, cnt = 0;
	for (int i = -2; i <= 2; i ++) vis[(x+i+n)%n] = 1;
	map <int, int> r;
	for (int i = -2; i <= 2; i ++)
		if (vis[(y+i+n)%n] && r.count((y+i+n)%n) == 0) {
			cnt ++; r[(y+i+n)%n] = 1;
		}
	return cnt;
}

int main() {
	fin >> n; 
	int a[6]; 
	for (int i = 0; i < 6; i ++) fin >> a[i];
	fout << 2*pow(min(5,n), 3) - dup(a[0], a[3]) * dup(a[1], a[4]) * dup(a[2], a[5]) << endl;
	return 0;
}

