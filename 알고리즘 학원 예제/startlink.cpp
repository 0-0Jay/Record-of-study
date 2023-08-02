// 백준 5014번 스타트링크 : https://www.acmicpc.net/problem/5014

#include<stdio.h>
#include<algorithm>
#include<queue>
#define M 2000000
using namespace std;

int f, s, g, u, d, chk[1000001];
queue<pair<int, int>> que;

int main() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	que.push({ s, 0 });  // 큐에 초기값으로 현재위치와 이동횟수 0회 저장
	chk[s] = 1;  // 현재 위치 중복 체크 방지
	while (!que.empty()) {
		int now = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (now == g) {  // 만약 g층에 도착하면 cnt를 출력하고 프로그램 종료
			printf("%d ", cnt);
			return 0;
		}
		if (u > 0 && now + u <= f && chk[now + u] == 0) {  // u가 0보다 크고, now + u가 f층 이하이며, 방문한 적이 없으면 큐에 저장
			que.push({ now + u, cnt + 1 });
			chk[now + u] = 1;
		}
		if (d > 0 && now - d >= 1 && chk[now - d] == 0) {  // d가 0보다 크고, now - d가 f층 이하이며, 방문한 적이 없으면 큐에 저장
			que.push({ now - d, cnt + 1 });
			chk[now - d] = 1;
		}
	}
	printf("use the stairs");  // BFS로 모두 순회했음에도 g층에 도착하지 못하면 출력
	return 0;
}
