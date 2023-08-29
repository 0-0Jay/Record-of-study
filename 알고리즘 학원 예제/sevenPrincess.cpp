// 백준 1941번 소문난 칠공주 : https://www.acmicpc.net/problem/1941

#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

char arr[5][6];
int cnt, tmp[5][5], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

bool check(int t) {  // BFS로 모두 연결되어 있는지 확인하는 함수
	queue<int> que;
	que.push(t);
	int chk[25] = { 0, };  // 중복방문 방지를 위한 chk배열 초기화
	chk[t] = 1;
	int w = 1;
	while (!que.empty()) {  // BFS를 이용해 w(연결된 영역의 크기) 계산
		int now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int a = (now / 5) + dx[i];
			int b = (now % 5) + dy[i];
			if (a > -1 && a < 5 && b > -1 && b < 5 && tmp[a][b] == 1 && chk[a * 5 + b] == 0) {
				w++;
				chk[a * 5 + b] = 1;
				que.push(a * 5 + b);
			}
		}
	}
	if (w == 7) return true;  // w가 7이면 true, 그 외에는 false 반환
	return false;
}

void select(int t, int d, int yn) {  // 백트래킹으로 자리를 선택하는 함수
	if (yn >= 4) return;  // 임도연파가 4명 이상일 경우 이다솜파가 더 적어지므로 return
	if (d == 7) {  // 7명을 인원문제없이 뽑았으면 자리배치가 모두 이어져있는지 체크하여 만족하면 카운팅
		if (check(t)) cnt++;
		return;
	}
	for (int i = t + 1; i < 25; i++) {  // 2차원(5 x 5)을 1차원(25)으로 변경하여 코드 단순화
		int x = i / 5, y = i % 5;
		tmp[x][y] = 1;  // 선택한 자리는 표시
		if (arr[x][y] == 'Y') select(i, d + 1, yn + 1); // 만약 선택한 자리가 Y면 yn에 카운팅
		else select(i, d + 1, yn);
		tmp[x][y] = 0;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%s", arr[i]);
	}
	select(-1, 0, 0);
	printf("%d", cnt);
	return 0;
}
