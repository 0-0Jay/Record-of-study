// 백준 15663번 N과 M(9) : https://www.acmicpc.net/problem/15663

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[10], res[10], chk[10], n, m;

void DFS(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
    int bef = 0;  // 주어지는 숫자가 자연수이기 때문에 초기값을 0으로 설정
    for (int i = 0; i < n; i++) {
        if (chk[i] != 1 && arr[i] != bef) {  // 같은 숫자가 수열에 존재할 수 있으므로 중복을 인덱스로 체크
            res[d] = arr[i];
            bef = res[d];  // 이번 탐색에 사용한 숫자를 다음 탐색에 또 사용하지 않게 bef에 저장해여 중복 체크
            chk[i] = 1;
            DFS(d + 1, i);
            chk[i] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    DFS(0);
    return 0;
}
