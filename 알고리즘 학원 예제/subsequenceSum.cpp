// 백준 1182번 부분수열의 합 : https://www.acmicpc.net/problem/1182

#include <stdio.h>
#include <algorithm>
#define M 100001
using namespace std;

int arr[M], n, s, cnt;

void DFS(int sum, int now) {  // 조건이 부분수열이므로 방금 탐색한 인덱스를 now에 저장에서 다음에 위치한 수부터 탐색
	if (sum == s) cnt++;  // sum이 s가 되는 모든 순간을 카운팅 해야하기 때문에 따로 return 조건을 주지 않고 완전 탐색
	for (int i = now; i < n; i++) {
		DFS(sum + arr[i], i + 1);
	}
}

int main() {
	scanf("%d %d", &n, &s);
	if (s == 0) cnt--;  // DFS에 들어가기전 초기값을 0으로 줄 것이므로 만약 목표값이 0이라면 초기값을 배제하기 위해 -1
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	DFS(0, 0);
	printf("%d", cnt);
	return 0;
}
