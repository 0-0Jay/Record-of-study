// 백준 14697번 방 배정하기 : https://www.acmicpc.net/problem/14697

#include <stdio.h>
#include <algorithm>

int main() {
	int a, b, c, n;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	for (int i = 0; i <= n; i += a) {  // 각 방을 추가하는 경우를 완전 탐색, 총합이 n 이하인 경우만 탐색
		for (int j = 0; i + j <= n; j += b) {
			for (int k = 0; i + j + k <= n; k += c) {
				if (i + j + k == n) {
					printf("1");  // 한번이라도 n과 같아지면 1 출력 후 프로그램 종료
					exit(0);
				} 
			}
		}
	}
	printf("0");  // exit(0)가 동작하지 않았다면 어떤 경우도 n과 같아지지 않았으므로 0 출력
	return 0;
}
