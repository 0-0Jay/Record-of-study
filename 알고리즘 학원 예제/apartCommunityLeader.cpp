// 백준 2775번 부녀회장이 될테야 : https://www.acmicpc.net/problem/2775

#include <stdio.h>
#include <algorithm>
using namespace std;

int cnt[15][15];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= 14; i++) {
		cnt[0][i] = i;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j];
		}
	}
	for (int i = 0; i < t; i++) {
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%d\n", cnt[k][n]);
	}
	return 0;
}
