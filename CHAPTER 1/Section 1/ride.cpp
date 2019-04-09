/*
ID: lfshinj1
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("ride.in");
ofstream fout("ride.out");

int main() {
	string s1, s2; 
	fin >> s1 >> s2;
	int x1 = 1, x2 = 1;
	for (int i = 0; i < s1.size(); i ++) {
		x1 = x1 * (s1[i]-'A'+1) % 47;
	}
	for (int i = 0; i < s2.size(); i ++) {
		x2 = x2 * (s2[i]-'A'+1) % 47;
	}
	if (x1 == x2) fout << "GO\n";
	else fout << "STAY\n";
	
	return 0;
}
