// 백준 15970번 화살표 그리기 : https://www.acmicpc.net/problem/15970

#include <stdio.h>
#include <algorithm>
#define M 5001
using namespace std;

struct tmp {
	int loc, col;
};

int chk(tmp i, tmp j) {
	return i.col < j.col || i.col == j.col && i.loc < j.loc;
}

tmp point[M];
int sum = 0;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point[i].loc, &point[i].col);
	}
	sort(point, point + n, chk);  // 같은 색상끼리 정렬, 색이 같으면 위치순으로 정렬
	sum = point[1].loc - point[0].loc + point[n - 1].loc - point[n - 2].loc;  // 맨 첫 점과 마지막 점은 가장 가까운 점 하나가 끝이므로 미리 계산
	for (int i = 1; i < n - 1; i++) {
		int min = 100001;
		if (point[i].col == point[i - 1].col && min > point[i].loc - point[i - 1].loc) min = point[i].loc - point[i - 1].loc;
		if (point[i].col == point[i + 1].col && min > point[i + 1].loc - point[i].loc) min = point[i + 1].loc - point[i].loc;
		sum += min;  // 이전 점과 색이 같으면 최소값 비교. 다음 점과 색이 같으면 최소값 비교. 최종 최소값 누적
	}
	printf("%d", sum);
	return 0;
}
