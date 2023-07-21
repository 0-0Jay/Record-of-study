// 백준 1463번 1로 만들기 : https://www.acmicpc.net/problem/1463

#include <stdio.h>
#include <algorithm>
using namespace std;

int cnt[1000001];

int main() {
	int n;
	scanf("%d", &n);
	cnt[2] = 1;  // 1일 때는 0, 2일 때는 1, 3일 때는 1로 미리 cnt에 저장
	cnt[3] = 1;
	for (int i = 4; i <= n; i++) {
		int min = 100000;
		if (cnt[i - 1] != 0 && min > cnt[i - 1]) min = cnt[i - 1];  // i - 1의 경우
		if (i % 3 == 0 && min > cnt[i / 3]) min = cnt[i / 3];  // i / 3의 경우
		if (i % 2 == 0 && min > cnt[i / 2]) min = cnt[i / 2];  // i / 2의 경우
		cnt[i] = min + 1;  // 각 경우를 계산한 결과중 최소값에 + 1한 값을 cnt[i]에 저장
	}
	printf("%d", cnt[n]);  // -1의 경우가 있기 때문에 불가능한 경우는 존재하지 않음
	return 0;
}
