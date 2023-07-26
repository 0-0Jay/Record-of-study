#include <stdio.h>
#include <algorithm>
#define M 100001
using namespace std;

int arr[M], res[M], m = -0x7fffffff;  // 최대값이 음수일 경우도 존재하므로 정수 최소값으로 m 설정

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] = max(arr[i - 1] + arr[i], arr[i]);  // 값을 입력 받으면, 누적합과 지금 수를 비교해 더 큰값으로 변경
		if (m < arr[i]) m = arr[i];  // 최대값 계산
	}
	printf("%d", m);
	return 0;
}
