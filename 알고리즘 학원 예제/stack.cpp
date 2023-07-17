// 백준 10828번 스택 : https://www.acmicpc.net/problem/10828

#include <stdio.h>
#include <string.h>
using namespace std;

char cmd[6];
int stk[10000], key = 0;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &stk[key++]);
		}
		else if (strcmp(cmd, "top") == 0) {
			if (key > 0) printf("%d\n", stk[key - 1]);
			else printf("-1\n");
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", key);
		}
		else if (strcmp(cmd, "empty") == 0) {
			if (key == 0) printf("1\n");
			else printf("%d\n", 0);
		}
		else if (strcmp(cmd, "pop") == 0) {
			if (key > 0) printf("%d\n", stk[--key]);
			else printf("-1\n");
		}
	}
	return 0;
}
