// 백준 2485번 가로수 : https://www.acmicpc.net/problem/2485

#include <stdio.h>
using namespace std;

int arr[100000], tmp[100000];

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (i > 0) tmp[i] = arr[i] - arr[i - 1];  // tmp에 이미 심은 나무의 간격 저장
	}
	for (int i = 1; i < n - 1; i++) {  // 모든 간격의 최대공약수 계산
		int r = 0;
		int a = tmp[i];
		int b = tmp[i + 1];
		while (b > 0) {
			r = a % b;
			a = b;
			b = r;
		}
		tmp[i + 1] = a;
	}
	for (int i = 0; i < n - 1; i++) {  // 각 간격에 새로 심을 나무 카운팅
		cnt += (arr[i + 1] - arr[i]) / tmp[n - 1] - 1;
	}
	printf("%d", cnt);
	return 0;
}
