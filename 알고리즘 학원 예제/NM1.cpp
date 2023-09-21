// 백준 15649번 N과 M(1) : https://www.acmicpc.net/problem/15649

#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[10], chk[10];
int n, m;

void DFS(int num, int d) {
	if (d == m) {  // 만약 깊이가 주어진 자릿수와 같아지면
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);  // arr에 저장된 숫자를 출력
		}
		printf("\n");  // 줄바꿈
		return;  // 백트래킹
	}
	chk[num] = 1;  // 중복된 숫자가 나오지 않게 해당 숫자를 체크
	for (int i = 1; i < n + 1; i++) {  // 1부터 n까지 숫자를 하나씩 대입
		if (chk[i] == 1) continue;  // 만약 한번이라도 나왔던 숫자라면 스킵
		arr[d] = i;  // 현재 깊이에 i를 삽입
		DFS(i, d + 1);  // 방금 삽입한 숫자와 (깊이 + 1)을 인수로 재귀함수 호출
	}
	chk[num] = 0; // 중복된 숫자가 체크 한 것을 다음 탐색에 영향을 주지 않게 초기화
}

int main() {
	scanf("%d%d", &n, &m);
	DFS(0, 0);
}
