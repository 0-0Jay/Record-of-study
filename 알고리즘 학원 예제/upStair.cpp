// 백준 2579번 계단 오르기 : https://www.acmicpc.net/problem/2579

#include <stdio.h>
#include <algorithm>
#define M 500
using namespace std;

int num[M], arr[M];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	arr[0] = num[0];  // 1번 칸에 도착하는 경우
	arr[1] = max(num[0] + num[1], num[1]);  // 2번 칸에 도착하는 경우(1 + 1, 2)
	arr[2] = max(num[0] + num[2], num[1] + num[2]);  // 3번 칸에 도착하는 경우(1 + 2, 2 + 1);
	for (int i = 3; i < n; i++) {
		arr[i] = max(arr[i - 2] + num[i], arr[i - 3] + num[i - 1] + num[i]);  // n번칸에 도착하는 경우
	}  // n - 2칸에서 +2 하는 경우, n - 3칸에서 +2 +1 하는 경우
	printf("%d", arr[n - 1]);
	return 0;
}
