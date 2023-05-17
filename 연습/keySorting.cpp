#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct tmp {
	int g, m;
};

vector<tmp> arr;
int ord[100], so, gord[100];

int chk(tmp i, tmp j) {
	if (so == 1) return ord[i.g] < ord[j.g] || i.m < j.m;
	if (so == 2) return ord[i.g] < ord[j.g] || i.m > j.m;
	if (so == 3) {
		return ord[i.g] < ord[j.g] || (gord[i.g] == 1 && ord[i.g] == ord[j.g] && i.m < j.m) || (gord[i.g] == 2 && ord[i.g] == ord[j.g] && i.m > j.m);
	}
	return 0;
};

int main() {
	int n;
	// 그룹 개수 입력
	scanf("%d", &n);
	// 값 입력
	while (1) {
		int g, m;
		scanf("%d%d", &g, &m);
		if (g < 1) break;
		if (g > n) {
			printf("잘못된 그룹 번호 입니다.\n");
			continue;
		}
		arr.push_back({ g,m });
	}
	// 사용자 지정 순서 설정
	printf("그룹별 사용자 지정 순서 설정\n");
	for (int i = 1; i <= n; i++) {
		printf("%d번 그룹이 위치할 순서 :", i);
		scanf("%d", &ord[i]);
	}
	// 그룹별 오름차순 내림차순 설정
	printf("그룹별 정렬 방식 설정\n");
	printf("1 ) 전체 오름차순\n");
	printf("2 ) 전체 내림차순\n");
	printf("3 ) 사용자 지정\n");
	printf("그룹별 정렬 설정 :");
	scanf("%d", &so);
	if (so == 3) {
		printf("오름차순 : 1 / 내림차순 : 2 / 정렬 안함 : 0\n");
		for (int i = 1; i <= n; i++) {
			printf("%d번 그룹 정렬 방법 : ", i);
			scanf("%d", &gord[i]);
		}
	}
	// 정렬
	sort(arr.begin(), arr.end(), chk);
	for (int i = 0; i < arr.size(); i++) {
		printf("(%d, %d)\n", arr[i].g, arr[i].m);
	}
}

// order를 사용자가 임의로 지정하여 정렬하는 프로그램
// 기존의 오름차순과 내림차순에 더불어 1-5-2-4-3과 같은 임의 정렬도 가능
