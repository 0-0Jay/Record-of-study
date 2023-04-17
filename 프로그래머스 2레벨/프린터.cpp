#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct tmp {
    int p, l;
};
int chk (int i, int j) {
    return i > j;
}
queue<tmp> printer;
int solution(vector<int> priorities, int location) {
    for (int i = 0; i < priorities.size(); i++) {
        printer.push({priorities[i], i});
    }
    sort(priorities.begin(), priorities.end(), chk);
    int k = 0;
    while(1) {
        if (printer.front().p < priorities[k]) {
            printer.push({printer.front().p, printer.front().l});
            printer.pop();
        } else {
            k++;
            if (printer.front().l == location) break;
            printer.pop();
        }
    }
    return k;
}
