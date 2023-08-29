// 백준 14502번 연구소 : https://www.acmicpc.net/problem/14502

#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, safe, arr[8][8], tmp[8][8], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, minv = 65, v = 0;

void virus(int x, int y) {
	v++;  // 시작지점 카운팅
	tmp[x][y] = 1;
	queue < pair<int, int> > que;
	que.push({ x , y });
	while (!que.empty()) {  // BFS를 통해 바이러스가 퍼질때마다 v에 카운팅
		pair<int, int> now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int a = now.first + dx[i];
			int b = now.second + dy[i];
			if (a > -1 && a < n && b > -1 && b < m && tmp[a][b] == 0) {
				tmp[a][b] = 1;  // 바이러스가 퍼진 곳은 벽으로 전환해도 무관(0의 갯수만 필요하기 때문)
				v++;
				que.push({ a,b });
			}
		}
	}
}

void wall(int a, int d) {
	if (d == 3) {  // 벽을 3개 세웠으면 수행
		v = 0;  // v를 0으로 초기화
		copy(&arr[0][0], &arr[0][0] + 64, &tmp[0][0]);  // arr배열에 BFS 탐색을 하지 않고 tmp에 복사하여 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 2) {  // 전체 탐색 중 바이러스 발견 시 BFS 탐색 시작
					virus(i, j);
				}
			}
		}
		if (minv > v) minv = v;  // 바이러스 갯수의 최소값 계산
		return;
	}
	for (int i = a + 1; i < n * m; i++) {  // 1차원처럼 계산하여 코드 단순화
		if (arr[i / m][i % m] == 0) {
			arr[i / m][i % m] = 1;
			wall(i, d + 1);
			arr[i / m][i % m] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0 || arr[i][j] == 2) safe++;  // 초기 안전구역의 수 카운팅. 바이러스 시작지점도 같이 카운팅(추후 계산 과정에서 차감)
		}
	}
	wall(-1, 0);
	printf("%d", safe - minv - 3);  // 총 안전구역 - 최소 바이러스 갯수 - 벽 개수
	return 0;
}
