// 백준 번 불!

#include<stdio.h>
#include<algorithm>
#include<queue>
#define M 1002
using namespace std;

char map[M][M];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, jchk[M][M], fchk[M][M];
queue<pair<int, int>> que;  // 불과 지훈의 큐를 따로 사용
queue<pair<int, int>> fire;

int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'J') {  // 지훈이의 좌표를 큐에 초기값으로 지정
				que.push({ i, j });
				jchk[i][j] = 1;
			}
			if (map[i][j] == 'F') {  // 불의 모든 좌표를 큐에 초기값으로 지정
				fire.push({ i, j });
				fchk[i][j] = 1;
			}
		}
	}
	while (!fire.empty()) {  // 불의 확산을 미리 BFS로 계산
		pair<int, int> f = fire.front();
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int fx = f.first + dx[i];
			int fy = f.second + dy[i];
			if (fchk[fx][fy] == 0 && (map[fx][fy] == '.' || map[fx][fy] == 'J')) {
				fchk[fx][fy] = fchk[f.first][f.second] + 1;
				fire.push({ fx, fy });
			}
		}
	}
	
	while (!que.empty()) {  // 지훈의 이동을 BFS로 계산
		pair<int, int> ji = que.front();
		que.pop();
		if (ji.first == 1 || ji.first == r || ji.second == 1 || ji.second == c) {  // 어디든 테두리에 닿았으면 답 출력
			printf("%d", jchk[ji.first][ji.second]);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = ji.first + dx[i];
			int ny = ji.second + dy[i];
			int cnt = jchk[ji.first][ji.second] + 1;
			if (jchk[nx][ny] == 0 && map[nx][ny] == '.' && (cnt < fchk[nx][ny] || fchk[nx][ny] == 0)) {  // 불이 지나간적이 없고, 벽이 아니면서 이전에 방문한 적이 없으면 수행
				que.push({ nx, ny });
				jchk[nx][ny] = cnt;
			}
		}
	}
	
	printf("IMPOSSIBLE");
	return 0;
}
