// 백준 10163번 색종이 : https://www.acmicpc.net/problem/10163

#include <stdio.h>
using namespace std;

int paper[1002][1002], color[101];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x1 + x2; j++) {
			for (int k = y1; k < y1 + y2; k++) {
				paper[j][k] = i;  // 각 색종이의 크기만큼 해당 범위에 덮어 씌움
			}
		}
	}
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			color[paper[i][j]]++;  // 처음부터 끝까지 돌면서 해당 색종이에서 보이는 부분 카운팅
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", color[i]);
	}
	return 0;
}
