// 백준 2805번 나무 자르기 : https://www.acmicpc.net/problem/2805

#include <stdio.h>
# define M 1000100

long long tree[M];

int main() {
	int n;
	long long m, l , r, mid, sum, max = 0, ans;
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] > max) max = tree[i];  // 데이터를 받을때 미리 최대 나무 크기를 저장해 탐색 범위 축소
	}
	l = 0, r = max;  // 절단한 나무의 총 길이를 이진 탐색
	while (1) {
		if (l > r) break;
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		if (sum >= m) {  // 절단 나무의 총 길이가 필요한 나무 길이 이상이면 ans에 임시저장 해두고 값을 높여서 한 번 더 탐색
			ans = mid;
			l = mid + 1;
		}
		else if (sum < m) r = mid - 1;  // 아니면 값을 차감하여 탐색
	}
	printf("%d", ans);
}
