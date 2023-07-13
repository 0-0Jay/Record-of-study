// 백준 25400번 제자리 : https://www.acmicpc.net/problem/25400

#include <stdio.h>

int n, tmp = 1, num, cnt;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {  // 각 자리 숫자를 tmp(현재 찾는 수)와 비교
		scanf("%d", &num);  // 실제 수 배열을 만들 필요 없음. 각 자릿수와 탐색중인 수만 비교하면 되는 그리디 문제
		if (num != tmp) cnt++;  // 다르면 제거 카운팅
		else tmp++;  // 같으면 다음 수 탐색
	}
	printf("%d", cnt);  // 제거한 횟수 추가
	return 0;
}
