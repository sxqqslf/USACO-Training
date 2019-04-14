/*
ID: lfshinj1
TASK: dualpal
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

string trans(int num, int b) {
	string s = "";
	while (num) {
		s += to_string(num % b);
		num /= b;
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
	int n, s; fin >> n >> s;
	while (n) {
		s ++;
		int cnt = 0;
		for (int b = 2; b <= 10; b ++) {
			string str = trans(s, b);
			if (ispal(str)) { cnt ++; }
			if (cnt >= 2) break;
		}
		if (cnt >= 2) { fout << s << endl; n --; }
	}
	return 0;
}

