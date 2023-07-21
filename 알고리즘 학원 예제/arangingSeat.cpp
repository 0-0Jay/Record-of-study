// 백준 10157번 자리배정 : https://www.acmicpc.net/problem/10157

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int arr[1001][1001];

int main() {
	int c, r, k, min, cnt = 0;
	scanf("%d%d%d", &c, &r, &k);
	min = (c < r) ? c : r;
	int x = 1, y = 0, v = 1;
	for (int i = 1; i <= min; i++) {  // 달팽이 배열 방법
		for (int j = 1; j <= r; j++) {  // 행방향으로 채우기
			y += v;
			arr[x][y] = ++cnt;
			if (cnt == k) { printf("%d %d", x, y); return 0; }
		}
		r--; c--;  // 안쪽으로 갈수록 행길이와 열길이가 1씩 감소
		for (int j = 1; j <= c; j++) {  // 열방향으로 채우기
			x += v;
			arr[x][y] = ++cnt;
			if (cnt == k) { printf("%d %d", x, y); return 0; }
		}
		v *= -1;  // 행방향 1회, 열방향 1회 반복 수행했으면, v의 부호를 변환해서 방향 컨트롤
	}
	printf("0");  // 모든 배열을 채웠음에도 return이 수행되지 않았다면, 0 출력
	return 0;
}
