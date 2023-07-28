// 백준 13023번 ABCDE : https://www.acmicpc.net/problem/13023

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, chk[2001], res;
vector<int> arr[2001];

void DFS(int d, int now) {
	if (res == 1) return;  // 이미 가능한 경우가 발견 되었으면 추가 탐색 방지 
	if (d == 5) {  // 5명이 일자로 연결된 경우가 발생하면 res를 1로 변경
		res = 1;
		return;
	}
	for (int i = 0; i < arr[now].size(); i++) {
		if (chk[arr[now][i]] == 0) {  // 무한 탐색 방지를 위해 한번 탐색한 인원은 체크
			chk[arr[now][i]] = 1;
			DFS(d + 1, arr[now][i]);
			chk[arr[now][i]] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
  for (int i = 0; i < n; i++) {  // 시작점을 0 ~ n 까지 탐색
		chk[i] = 1;
		DFS(1, i);
		chk[i] = 0;
    if (res == 1) break;  // 마찬가지로 res가 1이 발생했으면 추가 탐색 방지
	}
	printf("%d", res);
	return 0;
}
