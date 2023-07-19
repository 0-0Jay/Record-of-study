// 백준 1764번 듣보잡 : https://www.acmicpc.net/problem/1764

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#define M 500000
using namespace std;

string dn[M], res[M];
int k;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n + m; i++) {  // 듣지 못한 사람과 보지 못한 사람을 한 배열에 전부 저장
		cin >> dn[i];
	}
	sort(dn, dn + n + m);  // 알파벳 순으로 정렬
	for (int i = 0; i < n + m - 1; i++) {
		if (dn[i] == dn[i + 1]) {  // 현재 탐색중인 단어가 다음 단어와 같으면 듣도 보도 못한 사람이므로 결과배열에 저장
			res[k++] = dn[i];
		}
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}
