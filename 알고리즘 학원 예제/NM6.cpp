// 백준 15663번 N과 M(6) : https://www.acmicpc.net/problem/15663

#include <stdio.h>
#include <algorithm>
#define M 10
using namespace std;

int num[M], arr[M], n, m;

void DFS(int d, int now) {
	if (d == m) {
		for (int i = 0; i < d; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = now; i < n; i++) {
		arr[d] = num[i];
		DFS(d + 1, i + 1);
	}

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	DFS(0, 0);
	return 0;
}
