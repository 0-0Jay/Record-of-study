// 백준 10815번 숫자 카드 : https://www.acmicpc.net/problem/10815

#include <stdio.h>
#include <algorithm>
#define M 500010
using namespace std;

int arr[M], now;

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);  // 이진 탐색을 위해 정렬
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &now);
		int l = 0, r = n - 1, mid = (l + r) / 2;  // 배열 이진 탐색
		while (l <= r) {
			mid = (l + r) / 2;
			if (arr[mid] > now) r = mid - 1;
			else if (arr[mid] < now) l = mid + 1;
			else {
				printf("1 ");  // 같은 값이 나오면 1 출력 후 탐색 중단
				break;
			}
		}
		if (l > r) printf("0 ");  // 모든 탐색 이후에도 1이 출력되지 않았다면 0 출력
	}
	return 0;
}
