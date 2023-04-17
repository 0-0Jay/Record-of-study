#include <string>
#include <vector>
using namespace std;
vector<int> fin;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    for (int i = 0; i < progresses.size(); i++) {
        double r = (double)(100 - progresses[i]) / speeds[i];
        if ((int)r != r) r += 1;
        fin.push_back((int)r);
    }
    vector<int> answer;
    for (int i = 0; i < fin.size(); i++) {
        if (fin[i] == 101) continue;
        int cnt = 1;
        for (int j = i + 1; j < fin.size(); j++) {
            if (fin[i] >= fin[j]) {
                cnt++;
                fin[j] = 101;
            } else {
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
