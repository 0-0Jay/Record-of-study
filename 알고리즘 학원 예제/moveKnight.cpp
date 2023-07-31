// 백준 7562번 나이트의 이동 : https://www.acmicpc.net/problem/7562

#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 310
using namespace std;

int board[M][M], chk[M][M], que[M * M][2], st, ed, dx[8] = {1, 2, 2, 1, -1, -2, -2 ,-1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s, x1, y1, x2, y2;
		scanf("%d %d %d %d %d", &s, &x1, &y1, &x2, &y2);
		fill(&chk[0][0], &chk[s][s], 0);  // 매 탐색마다 사용할 범위를 0으로 초기화
		st = ed = -1;
		que[++st][0] = x1;
		que[st][1] = y1;
		chk[x1][y1] = 1;  // 시작지점의 값을 1로 주어 후에 chk[tx][ty] == 0 조건에 true가 반환되지 않도록 방지
		while (st != ed) {
			int nx = que[++ed][0];
			int ny = que[ed][1];
			if (nx == x2 && ny == y2) {  // 큐에서 뽑은 값이 목적지면 chk에 저장된 수 - 1을 출력 (시작을 0이 아닌 1로 했기 때문)
				printf("%d\n", chk[nx][ny] - 1);
				break;
			}
			for (int i = 0; i < 8; i++) {  // dx와 dy에 미리 나이트가 움직일 x, y 이동 값 8개를 지정하여 반복문으로 한번에 수행
				int tx = nx + dx[i];
				int ty = ny + dy[i];
				if (tx >= 0 && tx < s && ty >= 0 && ty < s && chk[tx][ty] == 0) {  // 체스판 범위 안이며, 방문한 적이 없으면 수행
					chk[tx][ty] = chk[nx][ny] + 1;  // 현재칸 + 1의 값을 chk에 저장하여 중복 탐색 방지와 이동 횟수를 동시에 체크
					que[++st][0] = tx;
					que[st][1] = ty;
				}
			}
		}
	}
	return 0;
}
