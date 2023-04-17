#include <string>
#include <vector>
using namespace std;
int cnt = 0, s, arr[20], num[20], sum, tar;
void tg (int d) {
    if (d == s) {
        for (int i = 0; i < d; i++) {
            sum += arr[i];
        }
        if (sum == tar) {
            cnt++; sum = 0;
            return;
        } else {
            sum = 0;
            return;
        }
    }
    arr[d] = num[d];
    tg(d + 1);
    arr[d] = -num[d];
    tg(d + 1);
    return;
}
int solution(vector<int> numbers, int target) {
    s = numbers.size(), tar = target;
    for (int i = 0; i < s; i++) {
        num[i] = numbers[i];
    }
    tg(0);
    return cnt;
}
