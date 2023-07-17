// 백준 17618번 신기한 수 : https://www.acmicpc.net/problem/17618

#include <stdio.h>

int cnt;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp = i;  // 수를 활용하기위해 tmp에 i 저장
		int sum = 0;  // sum에 각 자릿수의 합 저장
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (i % sum == 0) cnt++;  // 나머지가 0이면 카운팅
	}
	printf("%d", cnt);
	return 0;
}
