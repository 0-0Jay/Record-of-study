// 백준 1012번 유기농 배추 : https://www.acmicpc.net/problem/1012

#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 51
using namespace std;

int map[M][M], que[M * M][2], st, ed, cnt, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		fill(&map[0][0], &map[x][y], 0);  // 매 테스트케이스마다 map, cnt 초기화
		cnt = 0;
		for (int i = 0; i < v; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			map[a][b] = 1;  // 배추가 존재하는 좌표는 1로 표시
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (map[i][j] == 1) {  // BFS를 수행할 때마다 하나의 집단에 소속된 배추들은 전부 0으로 변경되기 때문에 1이 발견되면 새로운 배추 집단이라는 의미
					cnt++;  // cnt(집단 수)를 1 올리고 BFS 수행
					st = ed = -1;
					que[++st][0] = i;
					que[st][1] = j;
					map[i][j] = 0; // 처음 발견된 배추를 0으로 변경
					while (st != ed) {
						int nowx = que[++ed][0];
						int nowy = que[ed][1];
						for (int d = 0; d < 4; d++) {
							int nx = nowx + dx[d];
							int ny = nowy + dy[d];
							if (nx >= 0 && nx < x && ny >= 0 && ny < y && map[nx][ny] == 1) {  // map 범위 내의 인접한 배추가 발견되면 수행
								map[nx][ny] = 0;  // 해당 배추를 0으로 낮추어 중복 탐색 방지
								que[++st][0] = nx;
								que[st][1] = ny;
							}
						}
					}
				}
			}
		}
		printf("%d\n", cnt);  // 테스트 케이스 당 cnt 출력
	}
	return 0;
}
