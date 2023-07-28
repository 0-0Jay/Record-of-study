// 백준 2606번 바이러스 : https://www.acmicpc.net/problem/2606

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int com[101][101], cnt, chk[101];
queue<int> que;

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < c; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		com[a][b] = com[b][a] = 1;
	}
	que.push(1), chk[1] = 1;
	while (!que.empty()) {  // BFS로 탐색
		int now = que.front();
		que.pop();
		for (int i = 1; i < 101; i++) {
			if (chk[i] == 0 && com[now][i] == 1) {  // 이미 바이러스가 퍼진 컴퓨터는 배제
				que.push(i);
				chk[i] = 1;
				cnt++;
				com[now][i] = com[i][now] = 0;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
