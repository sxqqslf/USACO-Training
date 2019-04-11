/*
ID: lfshinj1
TASK: transform
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("transform.in");
ofstream fout("transform.out");

void rotate90(string* s, int n) {
	string* t = new string[n];
	for (int i = 0; i < n; i ++) t[i] = s[i];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) 
			t[j][n-1-i] = s[i][j];
	}
	for (int i = 0; i < n; i ++) {
		s[i] = t[i];
	}
}

void reflection(string* s, int n) {
	for (int i = 0; i < n; i ++) { 
		for (int j = 0; j < n/2; j ++) {
			char ch = s[i][j]; 
			s[i][j] = s[i][n-1-j];
			s[i][n-1-j] = ch;
		}
	}
}

bool equal(string* s1, string* s2, int n) {
	for (int i = 0; i < n; i ++) 
		if (s1[i] != s2[i]) return false;
	return true;
}

int main() {
	int n; fin >> n;
	string* s1 = new string[20], *s2 = new string[20];
	for (int i = 0; i < n; i ++) fin >> s1[i];
	for (int i = 0; i < n; i ++) fin >> s2[i];
	int op = 7;
	if (equal(s1, s2, n)) op = 6;
	reflection(s1, n);
	if (equal(s1, s2, n)) op = min(op, 4);
	reflection(s1, n);
	rotate90(s1, n);
	if (equal(s1, s2, n)) op = min(op, 1);
	rotate90(s1, n);
	if (equal(s1, s2, n)) op = min(op, 2);
	rotate90(s1, n);
	if (equal(s1, s2, n)) op = min(op, 3);
	rotate90(s1, n);
	reflection(s1, n); rotate90(s1, n);
	if (equal(s1, s2, n)) op = min(op, 5);
	rotate90(s1, n);
	if (equal(s1, s2, n)) op = min(op, 5);
	rotate90(s1, n);
	if (equal(s1, s2, n)) op = min(op, 5);

	fout << op << endl; 
	delete[] s1; delete[] s2;

	return 0;
}
