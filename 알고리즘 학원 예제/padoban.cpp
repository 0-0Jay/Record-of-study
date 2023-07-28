// 백준 9461번 파도반 수열 : https://www.acmicpc.net/problem/9461

#include <stdio.h>
#include <algorithm>
using namespace std;

long long int p[101] = { 1, 1, 1, }; // 파도반 수열의 경우 77번째 항부터 int 범위 초과하므로 long long int로 설정

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 3; i < 100; i++) {  // DP를 위해 미리 0, 1, 2번 인덱스 설정
		p[i] = p[i - 2] + p[i - 3];  // 파도반 수열을 100번째 항까지 미리 계산
	}
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", p[n - 1]);
	}
	return 0;
}
