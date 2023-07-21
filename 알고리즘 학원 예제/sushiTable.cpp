// 백준 2531번 회전 초밥 : https://www.acmicpc.net/problem/2531

#include <stdio.h>
#include <algorithm>
using namespace std;

int sushi[30001], chk[3001], maxc, cnt;

int main() {
	int n, d, k, c;
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sushi[i]);  // 초밥 정보를 1차원 배열로 저장
	}
	for (int i = 0; i < n + k - 1; i++) {  // n + k - 1까지 탐색하면 한바퀴를 모두 돈 것과 같음
		chk[sushi[i % n]]++;  // 스시를 먹었으므로 체크
		if (chk[sushi[i % n]] == 1) cnt++;  // 위에서 체크되었을 때 1이면 방금 먹은 초밥은 처음 먹은 것이므로 카운팅
		if (i >= k - 1) {  // 먹어야하는 초밥 수가 되면
			if (i >= k) {  // 지나간 초밥 제거
				chk[sushi[i - k]]--;
				if (chk[sushi[i - k]] == 0) cnt--;
			}
			if (chk[c] == 0 && maxc < cnt + 1) maxc = cnt + 1;  // 먹은 초밥수의 최대값 비교 (쿠폰을 사용 / 미사용)
			else if (maxc < cnt) maxc = cnt;
		}
	}
	printf("%d", maxc);
	return 0;
}
