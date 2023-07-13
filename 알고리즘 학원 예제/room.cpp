// 백준 14697번 방 배정하기 : https://www.acmicpc.net/problem/14697

#include <stdio.h>
#include <algorithm>

int main() {
	int a, b, c, n;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	for (int i = 0; ; i += a) {  // 각 방을 추가하는 경우를 완전 탐색
		for (int j = 0; ; j += b) {
			for (int k = 0; ; k += c) {
				if (i + j + k == n) {
					printf("1");  // 한번이라도 n과 같아지면 1 출력 후 프로그램 종료
					exit(0);
				}
				if (i + j + k > n) break;  // 각 경우가 n보다 커지는 순간 해당 루트 반복 종료
			}
			if (i + j > n) break;
		}
		if (i > n) break;
	}
	printf("0");  // 가장 적은 침대를 가진 방 a만 사용하는 경우까지 탐색해도 n과 같아지지 않았으므로 0 출력
	return 0;
}
