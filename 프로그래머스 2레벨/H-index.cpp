#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int chk(int i, int j) {
    return i > j;
}
vector<int> arr;
int solution(vector<int> citations) {
    int answer = -1, cnt, max;
    sort(citations.begin(), citations.end(), chk);
    max = citations[0];
    for (int i = max; i >= 0; i--) {
        cnt = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i) {
                cnt++;
            }
        }
        if (cnt >= i) {
            answer = i;
            break;
        }
    }
    return answer;
}
