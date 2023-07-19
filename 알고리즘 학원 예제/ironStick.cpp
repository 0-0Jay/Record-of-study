// 백준 10799번 쇠막대기 : https://www.acmicpc.net/problem/10799

#include <stdio.h>
using namespace std;

char arr[100001];
int cnt, stick;

int main() {
	scanf("%s", arr);
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i] == '(') {  // '('가 나오면 막대 수, 전체 조각 수 카운팅
			stick++;
			cnt++;
		}
		else {  // ')'가 나오면
			if (arr[i - 1] == '(') {  // 이전 괄호가 '('면 레이저므로 현재 막대수를 전체 조각수에 카운팅
				stick--; cnt--;  // '()'면 레이저므로 막대와 전체 조각에서 앞서 막대로 카운팅 되었던 수를 차감
				cnt += stick;
			}
			else stick--;  // 이전 괄호가 ')'면 막대 하나 차감
		}
	}
	printf("%d", cnt);
	return 0;
}
