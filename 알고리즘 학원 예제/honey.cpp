// 백준 21758번 꿀 따기 : https://www.acmicpc.net/problem/21758

#include <stdio.h>
#define M 100000
using namespace std;
int honey[M], m;

int main() {  // 최대값이 되려면 벌1, 벌2, 벌집 3가지중 2개가 반드시 좌우측 끝에 위치해야 함을 이용하는 그리디 문제
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		honey[i] = honey[i - 1] + tmp;  // 배열에 각각 좌측 끝부터 누적합 저장
	}
	for (int i = 2; i < n; i++) {  // 벌을 양 끝에 배치
		int tmp = honey[i] - honey[1] + honey[n - 1] - honey[i - 1];
		if (m < tmp) m = tmp;
	}
	for (int i = 2; i < n; i++) {  // 벌통을 오른쪽 끝에 배치
		int tmp = (honey[n] - honey[i]) * 2 + honey[i - 1] - honey[1];
		if (m < tmp) m = tmp;
	}
	for (int i = 2; i < n; i++) {  // 벌통을 왼쪽 끝에 배치
		int tmp = honey[i - 1] * 2 + honey[n - 1] - honey[i];
		if (m < tmp) m = tmp;
	}
	printf("%d", m);
	return 0;
}
