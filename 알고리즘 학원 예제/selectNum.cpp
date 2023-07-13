// 백준 20186번 수 고르기 : https://www.acmicpc.net/problem/20186

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[5001], n, m, maxSum;

int chk(int i, int j) {  // 내림차순 정렬
	return i > j;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n, chk);  // 정렬 후 큰수부터 차례대로 뽑는 그리디 알고리즘 문제
	for (int i = 0; i < m; i++) {
		maxSum += arr[i] - i;  // i는 자연스럽게 이전에 뽑은 숫자의 개수
	}
	printf("%d", maxSum);
	return 0;
}
