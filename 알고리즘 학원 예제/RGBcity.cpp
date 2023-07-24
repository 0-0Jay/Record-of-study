// 백준 1149번 RGB 거리 : https://www.acmicpc.net/problem/1149

#include <stdio.h>
#include <algorithm>
#define M 1001
using namespace std;

int arr[M][3];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);  // 데이터를 받아서 이전 집에 색칠한 색을 제외한 색들 중 최소값을 누적
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}
	printf("%d", min(arr[n][0], min(arr[n][1], arr[n][2])));  // 세 집 중 최소값 출력
	return 0;
}
