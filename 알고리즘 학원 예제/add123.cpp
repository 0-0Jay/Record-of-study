// 백준 9095번 1, 2, 3 더하기 : https://www.acmicpc.net/problem/9095

#include <stdio.h>
using namespace std;

int cnt[11] = { 1, 1, 2, };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= 11; i++) {  // 최대 수가 11로 작은 수기 때문에 미리 11까지 구해놓음
		cnt[i] += cnt[i - 1] + cnt[i - 2] + cnt[i - 3];  // i는 i - (1 or 2 or 3)에서 (1 or 2 or 3)을 더한 경우과 같음
	}
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", cnt[num]);
	}
	return 0;
}
