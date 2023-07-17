// 백준 25401번 카드 바꾸기 : https://www.acmicpc.net/problem/25401

#include <stdio.h>
using namespace std;

int arr[500], m = 600;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((arr[j] - arr[i]) % (j - i) == 0) {  // 두수 i, j로 등차 수열을 만들 수 있는지 확인
				int cnt = 0;
				int tmp = (arr[j] - arr[i]) / (j - i);  // 등차 계산
				int now = arr[i] - tmp * i;
				for (int k = 0; k < n; k++) {  // i,j를 사용하는 등차수열에 포함되지 않는 수를 카운팅
					if (arr[k] != now) cnt++;
					now += tmp;
				}
				if (m > cnt) m = cnt;
			}
		}
	}
	printf("%d", m);
	return 0;
}
