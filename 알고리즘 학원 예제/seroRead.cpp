// 백준 10798번 세로읽기 : https://www.acmicpc.net/problem/10798

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string arr[5];

int main() {
	int m = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i].length() > m) m = arr[i].length();
	}
	for (int i = 0; i < m; i++) {  // 세로로 탐색
		for (int j = 0; j < 5; j++) {
			if (i < arr[j].length()) {  // 만약 i가 j문자열의 길이보다 길면 넘김
				cout << arr[j].substr(i, 1);
			}
		}
	}
	return 0;
}
