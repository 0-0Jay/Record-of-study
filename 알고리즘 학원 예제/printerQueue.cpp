// 백준 1966번 프린터 큐 : https://www.acmicpc.net/problem/1966

#include <stdio.h>
#include <algorithm>
using namespace std;

int prt[100], que[10000][2], st, ed;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, cnt = 0;
		scanf("%d%d", &a, &b);
		st = ed = -1;
		for (int j = 0; j < a; j++) {
			scanf("%d", &que[++st][0]);
			que[st][1] = j;
			prt[st] = que[st][0];  // 우선순위 정렬을 위한 배열 생성
		}
		sort(prt, prt + a);  // 오름차순 정렬 후, a번째 부터 탐색
		int key = a - 1;
		while (st != ed) {
			int now = que[++ed][0];  // 우선도 값과 해당 작업의 순번을 큐에서 꺼냄
			int nid = que[ed][1];
			if (now < prt[key]) {  // 만약 우선도가 더 높은 작업이 있으면 해당 작업을 큐의 마지막으로 보냄
				que[++st][0] = now;
				que[st][1] = nid;
			}
			else {
				cnt++;  // 수행 카운트
				key--;  // 다음으로 높은 우선도를 가진 작업으로 변경
				if (nid == b) {  // 작업 순번도 같으면 수행 카운트을 출력하고 break로 불필요한 탐색 방지
					printf("%d\n", cnt);
					break;
				}
			}
		}
	}
	return 0;
}
