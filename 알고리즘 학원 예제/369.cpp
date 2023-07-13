// 백준 17614번 369 : https://www.acmicpc.net/submit/17614

#include <stdio.h>
#include <algorithm>
using namespace std;

int n, cnt;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp > 0) {  // 각 자릿수가 3, 6, 9일때마다 카운팅
			if (tmp % 10 == 3 || tmp % 10 == 6 || tmp % 10 == 9) cnt++;
			tmp /= 10;
		}
	}
	printf("%d", cnt);
	return 0;
}
