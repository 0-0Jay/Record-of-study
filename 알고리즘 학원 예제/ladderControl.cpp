#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int board[31][11], n, m, h, cnt;

bool chk() {
	for (int i = 1; i <= n; i++) {  각 세로줄 별로 체크
		int y = i;
		for (int j = 1; j <= h; j++) {
			if (board[j][y] == 1) y++;  // 현재 칸이 1이면 오른쪽과 연결되어 있으니 y를 우측으로 이동
			else if (board[j][y - 1] == 1) y--;  // y - 1칸이 1이면 왼쪽과 연결되어 있으니 y를 좌측으로 이동
		}
		if (y != i) return false;  // 최종적으로 y가 i가 같은지 비교
	}
	return true;
}

void DFS(int a, int b, int d) {
	if (d == cnt) {
		if (chk()) {  // chk에서 true가 반환되었으면 d 출력 후 프로그램 종료
			printf("%d", d);
			exit(0);
		}
		return;
	}
	for (int i = a; i <= h; i++) {
		for (int j = b; j < n; j++) {
			if (!(board[i][j] + board[i][j - 1] + board[i][j + 1])) {  // 현재 탐색하는 지점 및 바로 양옆에 가로줄이 없는 경우 수행
				board[i][j] = 1;
				DFS(i, j + 1, d + 1);  // 가로줄 배치 후 오른쪽으로 한칸 이동하여 DFS 탐색
				board[i][j] = 0;
			}
		}
		b = 1;  // 처음에는 현재 행의 현재 열부터 오른쪽만 탐색하고, 다음 행부터는 1번 열부터 탐색하기 위해 b를 임의로 1로 초기화
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		board[a][b] = 1;
	}
	for (cnt = 0; cnt <= 3; cnt++) {  // 가로줄을 0 ~ 3개 추가하는 경우
		DFS(1, 1, 0);
	}
	printf("-1");  // 앞에서 exit(0)가 수행되지 않았으면 가능한 경우가 없다는 의미이므로 -1 출력
	return 0;
}
