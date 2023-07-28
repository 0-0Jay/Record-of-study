// 백준 3079번 입국심사 : https://www.acmicpc.net/problem/3079

#include <stdio.h>
#include <algorithm>
using namespace std;

long long int n, m, line[100001], minV = 1000000000;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &line[i]);
		minV = min(line[i], minV);  // 최소 대기 시간을 가진 줄을 계산.
	}
	long long int l = 1, r = minV * m, mid;  // 최소는 1, 최대는 최소 대기 시간 * 인원수로 설정
	while (l <= r) {
		mid = (l + r) / 2;
		long long int cnt = 0;  // 계산 도중 인원수가 int 범위를 벗어날 수 있기 때문에 cnt 또한 long long int로 설정
		for (int i = 0; i < n; i++) {
			cnt += mid / line[i];  // mid 시간동안 각 줄에서 처리할 수 있는 인원수를 cnt에 누적
		}
		if (cnt >= m) r = mid - 1;  // 만약 cnt가 실제 인원수보다 많거나 같으면 시간을 더 줄여서 탐색
		else l = mid + 1;
	}
	printf("%lld", l);
	return 0;
}
