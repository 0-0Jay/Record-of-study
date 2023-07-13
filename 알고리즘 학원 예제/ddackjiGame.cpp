// 백준 14696번 딱지놀이 : https://www.acmicpc.net/problem/14696

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a[5] = { 0, 0, 0, 0, 0 }, b[5] = { 0, 0, 0, 0, 0 };  // 카운팅을 위해 매 반복마다 0,0,0,0,0으로 초기화
		int t;
		scanf("%d", &t);  // a 딱지의 모양 별 카운팅
		for (int j = 0; j < t; j++) {
			int m;
			scanf("%d", &m);
			a[m]++;
		}
		scanf("%d", &t);  // b 딱지의 모양 별 카운팅
		for (int j = 0; j < t; j++) {
			int m;
			scanf("%d", &m);
			b[m]++;
		}
		int k;
		for (k = 4; k > 0; k--) {  // 4번 인덱스부터 역순으로 탐색
			if (a[k] > b[k]) {  // a[k]가 크면 A 출력 후 break;
				printf("A\n"); break;
			}
			if (a[k] < b[k]) {  // b[k]가 크면 B 출력 후 break;
				printf("B\n"); break;
			}
		}
		if (k == 0) printf("D\n");  // 반복문이 끝까지 돌았으면 D
	}

	return 0;
}
