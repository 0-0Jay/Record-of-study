#include <string>
#include <iostream>
#define M 100001
using namespace std;

int n;

void DFS(string now) {
	for (int i = 1; i <= now.length() / 2; i++) {
		if (now.substr(now.length() - i, i) == now.substr(now.length() - 2 * i, i)) return;  // 반복 구간 체크
	}
	if (now.length() == n) {  // 체크를 통과하고 수열의 길이가 n이 되면 출력 후, 프로그램 종료
		cout << now;
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		DFS(now + to_string(i));
	}
}

int main() {
	cin >> n;
	DFS("1");
	return 0;
}
