// 백준 2609번 최대공약수와 최소공배수 : https://www.acmicpc.net/problem/2609

#include <stdio.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a = n, b = m;
	while (b > 0) {  // 최대공약수 계산
		int r = a % b;
		a = b;
		b = r;
	}
	printf("%d\n%d", a, n * m / a);  // 최소공배수 = 두 수의 곱 / 최대공약수
	return 0;
}
