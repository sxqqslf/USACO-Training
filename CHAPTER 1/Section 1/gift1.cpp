/*
ID: lfshinj1
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
ifstream fin("gift1.in");
ofstream fout("gift1.out");

int main() {
	int n; fin >> n;
	string name[20];
	map <string, int> act;
	for (int i = 0; i < n; i ++) {
		fin >> name[i];
		act[name[i]] = 0;
	}
	for (int i = 0; i < n; i ++) {
		string s; fin >> s; 
		int give, m; fin >> give >> m;
		for (int j = 0; j < m; j ++) {
			string r; fin >> r;
			act[r] += give / m;
		}
		if (m != 0) act[s] -= give/m*m;		
	}
	for (int i = 0; i < n; i ++) {
		fout << name[i] << ' ' << act[name[i]] << endl;
	}
	return 0;
}
