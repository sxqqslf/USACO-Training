/*
ID: lfshinj1
TASK: palsquare
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

string ss = "ABCDEFGHIJK";
string trans(int n, int base) {
	string s = "";
	while (n) {
		if (n % base < 10) s += to_string(n % base);
		else s += ss[n%base-10]; 
		n /= base;
	}
	reverse(s.begin(), s.end());
	return s;
}

bool ispal(string s) {
	for (int i = 0; i < s.size()/2; i ++)
		if (s[i] != s[s.size()-1-i]) return false;
	return true;
}

int main() {
	int base; fin >> base;
	for (int i = 1; i <= 300; i ++) {
		int sqr = i * i;
		string val = trans(sqr, base);
		if (ispal(val)) { fout << trans(i, base) << ' ' << val << endl; }
	}
	return 0;
}
