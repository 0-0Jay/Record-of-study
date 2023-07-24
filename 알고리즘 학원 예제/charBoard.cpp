// 백준 2186번 문자판 : https://www.acmicpc.net/problem/2186

#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 101
using namespace std;

char alp[M][M], target[90];
int cnt, dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, k, dp[M][M][M], sum;

int main() {
	int n, m;
	scanf("%d%d%d\n", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			scanf("%c", &alp[i][j]);
		}
	}
	scanf("%s", target);
	int d = strlen(target);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (alp[i][j] == target[0]) dp[0][i][j] = 1;  // DP에 활용하기 위해 첫번째 문자와 일치하는 문자에 1씩 카운팅
		}
	}
	for (int i = 1; i < d; i++) {  // 두번째 알파벳부터 탐색
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				if (alp[j][l] == target[i]) {  // 만약 일치하는 알파벳이 있으면 탐색 시작
					for (int a = 0; a < 4; a++) {
						for (int b = 1; b <= k; b++) {  // 문자판 범위 안이면서 k 범위 이내의 이전 문자를 탐색
							int nx = j + dx[a] * b;
							int ny = l + dy[a] * b;
							if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
								dp[i][j][l] += dp[i - 1][j + dx[a] * b][l + dy[a] * b];  // 카운팅 누적
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += dp[d - 1][i][j];  // 마지막 문자에 대한 DP 배열을 탐색하여 모든 카운팅 합산
		}
	}
	printf("%d", sum);
	return 0;
}
