// 백준 1987번 알파벳 : https://www.acmicpc.net/problem/1987

#include <stdio.h>
#include <algorithm>
using namespace std;

int maxCount, chk[30], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
char map[22][22];

void DFS(int d, int x, int y) {
	if (d > maxCount) maxCount = d;  // 최대 이동 거리 계산
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];  // dx배열과 dy배열로 상하좌우 이동을 for문 하나로 묶어서 계산
		int ny = y + dy[i];
		if (chk[map[nx][ny] - 'A'] == 0 && map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {  // 범위 벗어나는 경우는 알파벳 범위를 활용해 배제
			chk[map[nx][ny] - 'A'] = 1;  // 같은 알파벳 중복 탐색 방지
			DFS(d + 1, nx, ny);
			chk[map[nx][ny] - 'A'] = 0;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	chk[map[1][1] - 'A'] = 1;  // 시작점 및 시작알파벳 체크
	DFS(1, 1, 1);
	printf("%d", maxCount);
	return 0;
}
