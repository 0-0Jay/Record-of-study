// 백준 15649번 N과 M(1) : https://www.acmicpc.net/problem/15649

#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[10], chk[10];
int n, m;

void DFS(int num, int d) {
	if (d == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	chk[num] = 1;
	for (int i = 1; i < n + 1; i++) {
		if (chk[i] == 1) continue;
		arr[d] = i;
		DFS(i, d + 1);
		chk[i] = 0;
	}
	chk[num] = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	DFS(0, 0);
}
