// 백준 1726번 로봇 : https://www.acmicpc.net/problem/1726

#include<stdio.h>
#include<algorithm>
using namespace std;

struct tmp {
	int x, y, l, cnt;
};

int orbit[101][101], n, m, stx, sty, stl, edx, edy, edl, chk[100][100][4], dl[5][2] = { {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} }, tl[5][2] = { {0,0}, {4, 3}, {3, 4}, {1, 2}, {2, 1} }, st, ed;
tmp que[10500];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &orbit[i][j]);
		}
	}
	scanf("%d%d%d %d%d%d", &stx, &sty, &stl, &edx, &edy, &edl);
	st = ed = -1;
	que[++st] = { stx, sty, stl, 0 };  // 큐에 초기값으로 시작 좌표, 시작 방향, 명령 카운트 저장
	chk[stx][sty][stl] = 1;
	while (st != ed) {
		tmp now = que[++ed];
		if (now.x == edx && now.y == edy && now.l == edl) {  // 도착 좌표, 방향이 나오면 출력 후 프로그램 종료
			printf("%d", now.cnt);
			return 0;
		}
		// 전진 1~3칸 한번에 이동 (1~3가지 경우)
		int a = now.x + dl[now.l][0];  // dl에 now.l에 따른 전진 이동 값을 미리 지정해두고 활용
		int b = now.y + dl[now.l][1];
		for (int i = 1; i <= 3 && orbit[a][b] == 0; i++) {  // 1~3칸의 경우를 탐색하되, 중간에 벽을 한번이라도 만나면 정지
			if (a > 0 && a <= n && b > 0 && b <= m && orbit[a][b] == 0 && chk[a][b][now.l] == 0) {
				chk[a][b][now.l] = 1;
				que[++st] = { a, b, now.l, now.cnt + 1 };  // 모든 조건을 만족하면 큐에 삽입
			}
			a += dl[now.l][0];
			b += dl[now.l][1];
		}
		// 좌 90도, 우 90도 회전 (2가지 경우)
		for (int i = 0; i < 2; i++) {
			if (chk[now.x][now.y][tl[now.l][i]] == 0) {  // 3차원 체크배열을 활용하여 각 좌표에서 동,서,남,북의 방향에 대한 중복 체크 수행
				chk[now.x][now.y][tl[now.l][i]] = 1;
				que[++st] = { now.x, now.y, tl[now.l][i], now.cnt + 1 };  // 모든 조건을 만족하면 큐에 삽입
			}
		}
	}
	return 0;
}
