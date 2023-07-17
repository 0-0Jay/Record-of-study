// 백준 2304번 창고 다각형 : https://www.acmicpc.net/problem/2304

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct tmp {
	int x, y;
};

int chk(tmp i, tmp j) {
	return i.x < j.x;
}

vector<tmp> arr;
int m, k, sum, top = -1;
tmp stk[1000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back({ a,b });
		if (b > m) k = a, m = b;  // 젤 높은 기둥을 기준으로 좌우의 넓이를 따로 계산
	}
	sort(arr.begin(), arr.end(), chk);  // x좌표 오름차순으로 정렬
	sum += m;  // 젤높은 기둥은 미리 sum에 누적
	for (int i = 0; arr[i].x <= k; i++) {  // 왼쪽 넒이 계산
		tmp now = arr[i];
		if (now.y >= stk[top].y) stk[++top] = now;
		if (top > 0 && now.y == stk[top].y) {
			sum += (stk[top].x - stk[top - 1].x) * stk[top - 1].y;
		}
	}
	top = -1;  // 오른쪽 하기전 스택 초기화
	for (int i = arr.size() - 1; arr[i].x >= k; i--) {  // 오른쪽 넓이 계산
		tmp now = arr[i];
		if (now.y >= stk[top].y) stk[++top] = now;
		if (top > 0 && now.y == stk[top].y) {
			sum += (stk[top - 1].x - stk[top].x) * stk[top - 1].y;
		}
	}
	printf("%d", sum);
	return 0;
}
