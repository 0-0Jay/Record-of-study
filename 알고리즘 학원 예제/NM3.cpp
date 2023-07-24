// 백준 15651번 N과 M(3) : https://www.acmicpc.net/problem/15651

#include <stdio.h>
#include <algorithm>
#define M 8
using namespace std;

int arr[M], n, m;

void DFS(int d) {
	if (d == m) {
		for (int i = 0; i < d; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[d] = i;
		DFS(d + 1);
	}

}

int main() {
	scanf("%d%d", &n, &m);
	DFS(0);
	return 0;
}
