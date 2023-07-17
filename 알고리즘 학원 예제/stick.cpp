// 백준 17608번 막대기 : https://www.acmicpc.net/problem/17608

#include <stdio.h>
using namespace std;

int stk[100010], k = -1;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int now;
		scanf("%d", &now);
		while (k > -1 && now >= stk[k]) k--;  // 스택에 막대기가 있을 때, 스택의 top과 now를 비교해서 now가 크면 스택에서 막대기 제거
		stk[++k] = now;  // 반복이 끝나면 해당 막대기를 스택에 push
	}
	printf("%d", k + 1);  // 우측에서 보이는 막대기 수 = 스택의 size
	return 0;
}
