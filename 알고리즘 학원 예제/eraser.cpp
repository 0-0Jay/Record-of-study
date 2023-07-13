// 백준 21756 지우개 : https://www.acmicpc.net/problem/21756

#include <stdio.h>

int arr[101];

int main() {
	int n, cnt;
	scanf("%d", &n);
	cnt = n;
	while (cnt > 1) {  // 배열에 남은 숫자가 1개가 될 때까지 반복
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1) continue;
			tmp++;
			if (tmp % 2 == 1) {  // 홀수 번마다 체크
				arr[i] = 1;
				cnt--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {  // 배열을 탐색해서 0인 숫자 출력 후 break
			printf("%d", i);
			break;
		}
	}
	return 0;
}


// 학원 풀이
/*
#include <stdio.h>

int arr[101];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	while (1) {
		if (n == 1) break;
		int tmp = 0;
		for (int i = 2; i <= n; i+=2) {
			arr[++tmp] = arr[i];
		}
		n = tmp;
	}
	printf("%d", arr[1]);
	return 0;
}
*/
