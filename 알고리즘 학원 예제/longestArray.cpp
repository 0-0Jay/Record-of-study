// 백준 11053번 가장 긴 증가하는 부분 수열 : https://www.acmicpc.net/problem/11053

#include <stdio.h>
#include <algorithm>
#define M 1001
using namespace std;

int arr[M], tmp[M], res = 0;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		tmp[i] = 1;  // 기본적으로 해당 수만 존재하는 길이가 1인 수열이 있음
		int maxtmp = 0, key = 0;
		for (int j = 1; j < i; j++) {  // 1번부터 i - 1번까지 탐색해서 가장긴 수열과 그 인덱스 탐색
			if (arr[i] > arr[j] && tmp[j] > maxtmp) {
				maxtmp = tmp[j];
				key = j;
			}
		}
		tmp[i] = tmp[key] + 1;  // 가장긴 수열 길이 + 1한 값을 tmp[i]에 저장
		if (tmp[i] > res) res = tmp[i];  // tmp[i]의 최대값 계산
	}
	printf("%d", res);
	return 0;
}
