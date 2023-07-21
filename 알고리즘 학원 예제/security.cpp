#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int map[100], res = 0;

int main() {
	int x, y, n;
	scanf("%d%d%d", &x, &y, &n);
	for (int i = 0; i <= n; i++) {  // 각 회당 p의 숫자에 따라 동, 서, 남, 북의 위치를 1차원상 위치로 변환
		int p, l;
		scanf("%d%d", &p, &l);
		if (p == 1) map[i] = l;
		else if (p == 2) map[i] = 2 * x + y - l;
		else if (p == 3) map[i] = 2 * (x + y) - l;
		else if (p == 4) map[i] = x + l;
	}
	for (int i = 0; i < n; i++) {
		int far = abs(map[n] - map[i]);
		res += (far < x + y) ? far : 2 * (x + y) - far;  // 맵의 가로 + 세로와 far를 비교해서 더 작은 수를 res에 누적
	}
	printf("%d", res);
	return 0;
}
