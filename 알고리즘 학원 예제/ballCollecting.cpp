// 백준 17615번 볼 모으기 : https://www.acmicpc.net/problem/17615

#include<stdio.h>
#define M 500010

char arr[M];
int min=0x7fffffff, r, b;

int main() {
	int n, cnt;
	scanf("%d ",&n);
		
	for (int i = 1; i <= n; i++) {  // 데이터를 받으면서 R과 B의 갯수 카운팅
		scanf("%c", &arr[i]);
		if(arr[i] == 'R') r++;
		else b++;
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {  // 빨강색공을 왼쪽으로 이동하는 경우
		if (arr[i] == 'R') cnt++;
		else break;
	}
	if (min > r - cnt) min = r - cnt;
	cnt = 0;
	for(int i = n; i >= 1; i--) {  // 빨강색공을 오른쪽으로 이동하는 경우
		if (arr[i] == 'R') cnt++;
		else break;
	}
	if (min > r - cnt) min = r - cnt;
	cnt = 0;
	for(int i = 1; i <= n; i++) {  // 파랑색공을 왼쪽으로 이동하는 경우
		if (arr[i] == 'B') cnt++;
		else break;
	}
	if (min > b - cnt) min = b - cnt;
	cnt = 0;
	for (int i = n; i >= 1; i--) {  // 파랑색공을 오른쪽으로 이동하는 경우
		if (arr[i] == 'B') cnt++;
		else break;
	}
	if (min > b - cnt) min = b - cnt;
	printf("%d", min);
	return 0;
}
