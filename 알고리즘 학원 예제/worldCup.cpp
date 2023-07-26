// 백준 6987번 월드컵 : https://www.acmicpc.net/problem/6987

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[6][3], res[4], flag;

void DFS(int a, int b, int d) {
	if (flag == 1) return;  // flag가 1이면 이미 가능한 게임이므로 추가 탐색 방지
	if (d == 15) flag = 1;  // 15게임을 모두 수행했다면 flag를 1로 변경
	if (b > 5) {  // b를 끝까지 탐색했으면 a를 한칸 내리고 탐색
		a++; b = a + 1;
	}
	if (arr[a][0] > 0 && arr[b][2] > 0) {  // a가 이긴 경우
		arr[a][0]--; arr[b][2]--;
		DFS(a, b + 1, d + 1);
		arr[a][0]++; arr[b][2]++;
	}
	if (arr[a][1] > 0 && arr[b][1] > 0) {  // 무승부인 경우
		arr[a][1]--; arr[b][1]--;
		DFS(a, b + 1, d + 1);
		arr[a][1]++; arr[b][1]++;
	}
	if (arr[a][2] > 0 && arr[b][0] > 0) {  // a가 진 경우
		arr[a][2]--; arr[b][0]--;
		DFS(a, b + 1, d + 1);
		arr[a][2]++; arr[b][0]++;
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		int wld = 0;  // 주어진 데이터에서 각 국가당 승, 무, 패 합이 올바른지 체크
		flag = 0;
		for (int j = 0; j < 6; j++) {
			int tmp = 0;
			for (int k = 0; k < 3; k++) {
				scanf("%d", &arr[j][k]);
				tmp += arr[j][k];
			}
			if (tmp != 5) wld = 1;
		}
		if (wld == 0) DFS(0, 1, 0);  // wld가 0이면 승, 무, 패는 이상이 없다는 뜻이므로 전체적으로 가능한 경우인지 탐색
		printf("%d ", flag);
	}
	return 0;
}
