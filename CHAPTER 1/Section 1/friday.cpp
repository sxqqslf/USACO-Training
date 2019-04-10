/*
ID: lfshinj1
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");

bool isLeapYear(int year) {
	return year % 100 != 0 && year % 4 == 0 || year % 400 == 0; 
}

int main() {
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int target[12] = {13}, t = 0;
	for (int i = 1; i < 12; i ++) {
		t += month[i-1];
		target[i] = t + 13;
	}
	int n; fin >> n;
	int st = 1, cnt[7] = {0};
	for (int i = 0; i < n; i ++) {
		bool leapYear = isLeapYear(1900 + i);
		int day = 365+leapYear;
		int tarIdx = 0;
		for (int j = 1; j <= day; j ++) {
			if (leapYear) {
				if (tarIdx < 2 && j == target[tarIdx] || tarIdx > 1 && j == target[tarIdx] + 1) {
					cnt[st] ++; tarIdx ++;
				}
			} else {
				if (j == target[tarIdx]) {
					cnt[st] ++; tarIdx ++;
				}
			}
			st = (st + 1) % 7;
		}
	}
	fout << cnt[6] << ' ' << cnt[0];
	for (int i = 1; i < 6; i ++) fout << ' ' << cnt[i];
	fout << endl;

	return 0;
}
