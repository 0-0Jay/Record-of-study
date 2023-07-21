// 백준 11726번 2xn 타일링 : https://www.acmicpc.net/problem/11726

#include <stdio.h>
#include <algorithm>
using namespace std;

int cnt[1001] = { 1, 1, };  // 0개를 만드는 경우는 아무것도 놓지 않는 1가지, 1을 만드는 경우는 1*2 하나를 놓는 1가지

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {  // 1과 2로 i를 만드는 경우의 수와 같음
		cnt[i] = (cnt[i - 1] + cnt[i - 2]) % 10007;  // (i-2에서 2*1을 2개 더 놓는 경우) + (i-1에서 1*2 하나를 더 놓는 경우)
	}
	printf("%d", cnt[n]);  // 계산하는 과정에서 %10007을 해주어야 중간에 오버플로우가 발생하지 않음
	return 0;
}
