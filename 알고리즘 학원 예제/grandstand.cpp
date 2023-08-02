// 백준 10166번 관중석 : https://www.acmicpc.net/problem/10166

#include<stdio.h>
#include<algorithm>
#include<set>
#define M 2000000
using namespace std;

set<double> s;  // 중복을 허용하지 않는 set 자료구조를 활용

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			s.insert((double)j / i);  // j / i의 값이 이미 set에 있으면 삽입 안함
		}
	}
	printf("%d", s.size());  // set의 크기가 겹치지 않는 관중석 수와 같음
	return 0;
}
