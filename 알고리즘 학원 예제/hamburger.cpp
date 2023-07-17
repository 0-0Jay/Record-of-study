// 백준 19941번 햄버거 분배 : https://www.acmicpc.net/problem/19941

#include <stdio.h>
using namespace std;

char arr[21000];
int cnt;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", arr);
	for (int i = 0; i < n; i++) {  // 왼쪽부터 탐색
		if (arr[i] == 'H') {  // 햄버거가 잡히면 다음 m칸중 가장 왼쪽에 있는 사람에게 분배
			for (int j = i + 1; j <= i + m; j++) {
				if (arr[j] == 'P') {
					cnt++ ;
					arr[i] = 0; arr[j] = 0;  // 분배가 완료된 사람, 햄버거는 0으로 체크
					break;
				}
			}
		}
		if (arr[i] == 'P') {  // 사람이 잡히면 다음 m칸 중 가장 왼쪽에 있는 햄버거 분배
			for (int j = i + 1; j <= i + m; j++) {
				if (arr[j] == 'H') {
					cnt++;
					arr[i] = 0; arr[j] = 0;  // 분배가 완료된 사람, 햄버거는 0으로 체크
					break;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}


// 학원 풀이
/*
#include <stdio.h>
using namespace std;

char arr[21000];
int cnt;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", arr);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'P') {
			for (int j = i - m; j <= i + m; j++) {  // 사람을 찾아서 좌우로 m칸 검사해서 가장 왼쪽의 햄버거 분배
				if (j < 0 || j > n - 1) continue;  // 탐색 범위가 문자열 범위를 벗어나면 continue로 오류 방지
				if (arr[j] == 'H') {
					cnt++;
					arr[j] = 0;
					break;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
*/
