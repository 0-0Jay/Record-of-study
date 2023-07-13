// 백준 25377번 빵 : https://www.acmicpc.net/problem/25377

#include <stdio.h>

int cnt = 1001;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a <= b && b < cnt) cnt = b;  // 가게 도착 시간이 빵 도착 시간 이하인 경우들 중 빵도착 시간의 최소값 탐색
	}
	if (cnt == 1001) cnt = -1;
	printf("%d", cnt);
	return 0;
}
