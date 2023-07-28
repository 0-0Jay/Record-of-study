// 백준 15686번 치킨 배달 : https://www.acmicpc.net/problem/15686

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct tmp {
	int x, y;
};

int n, m, city[51][51], cnt, ans, minFar = 0x7fffffff;
vector<tmp> chick, home;
vector<int> chk;

void DFS(int d, int now) {
	if (d == m) {  // m개의 치킨집을 선택했으면 수행
		int s = 0;
		for (int i = 0; i < home.size(); i++) {  // 집을 하나 선택
			int minH = 500;
			for (int j = 0; j < chk.size(); j++) {  // 선택된 각 치킨집과 거리를 비교해서 가장 짧은 거리를 s에 누적
				minH = min(abs(home[i].x - chick[chk[j]].x) + abs(home[i].y - chick[chk[j]].y), minH);
			}
			s += minH;
		}
		minFar = min(minFar, s);  // minFar에 최소값 계산
		return;
	}
	for (int i = now; i < chick.size(); i++) {  // 중복 탐색을 막기위해 now 변수를 활용
		chk.push_back(i);  // 선택한 치킨집은 인덱스로 chk에 저장
		DFS(d + 1, i + 1);
		chk.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &city[i][j]);
			if (city[i][j] == 2) {  // 치킨 집이면 chick배열에 좌표 저장
				chick.push_back({ i, j });
			}
			else if (city[i][j] == 1) {  // 집이면 home배열에 좌표 저장
				home.push_back({ i, j });
			}
		}
	}
	DFS(0, 0);
	printf("%d", minFar);
	return 0;
}
