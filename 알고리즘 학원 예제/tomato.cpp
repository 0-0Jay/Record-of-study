// 백준 7576번 토마토 : https://www.acmicpc.net/problem/7576

#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 1001
using namespace std;

int map[M][M], que[M * M][2], st = -1, ed = -1, cnt, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {  // n과 m이 가로 세로 이므로 배열에 넣을때는 외부for에 m을 지정
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[j][i]);
			if (map[j][i] == 1) {  // 만약 1이면 que에 삽입
				que[++st][0] = j;
				que[st][1] = i;
			}
		}
	}
	while (st != ed) {
		int nowx = que[++ed][0];
		int nowy = que[ed][1];
		for (int i = 0; i < 4; i++) {  // dx, dy로 미리 상하좌우 4방향을 지정해놓고 for문으로 한번에 수행
			int nx = nowx + dx[i];
			int ny = nowy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0) {  // 상자 범위 내에 값이 0이면 수행
				map[nx][ny] = map[nowx][nowy] + 1;  // 다음 칸에 현재칸 + 1을 넣어 중복체크와 시간카운팅을 동시에 수행
				que[++st][0] = nx;
				que[st][1] = ny;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {  // 만약 0이 하나라도 발견되면 -1 출력 후, return문으로 main 강제 종료
				printf("-1");
				return 0;
			}
			else if (map[i][j] > 0) {
				if (cnt < map[i][j]) cnt = map[i][j];  // cnt에 최대값 계산
			}
		}
	}
	printf("%d", cnt - 1);  // 시작을 1로 시작했으므로 결과값은 -1하여 출력
	return 0;
}
