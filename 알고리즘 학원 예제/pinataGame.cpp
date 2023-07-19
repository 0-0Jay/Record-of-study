#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += i;
	}
	if (n < sum) printf("-1"); // 분배가 가능하려면 반드시 1~k의 합보다 sum이 커야함
	else if ((n - sum) % k == 0) printf("%d", k - 1);  // 만약 n - sum이 k로 나누어 떨어지면, 그 최대차는 무조건 k-1
	else printf("%d", k); // 떨어지지 않는다면, 최대차는 k
	return 0;
}
