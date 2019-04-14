/*
ID: lfshinj1
TASK: namenum
LANG: C++
*/
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
ofstream fout("namenum.out");

map <string, int> dict;
string alpha = "ABCDEFGHIJKLMNOPRSTUVWXY";
bool flag = false;

void dfs(string s, string cur, int lvl) {
	if (cur.size() == s.size()) {
		if (dict.count(cur) != 0) { 
			fout << cur << endl;
			flag = true;
		}
		return ;
	}
	int d = s[lvl] - '0';
	for (int i = (d-2)*3; i < (d-1)*3; i ++) {
		dfs(s, cur + alpha[i], lvl + 1);
	}
}

int main() {
	ifstream fin("dict.txt");
	int num = 5000;
	for (int i = 0; i < num; i ++) {
		string word; fin >> word;
		dict[word] = 1;
	}
	fin.close();
	ifstream in("namenum.in");

	string n; in >> n;	
	dfs(n, "", 0);
	if (!flag) { fout << "NONE\n"; }
	return 0;
}
