#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct tmp {
	int size, cnt;
};

int chk(tmp i, tmp j) {
	return i.cnt > j.cnt;
}

vector<tmp> freq;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    for (int i = 0; i < tangerine.size(); i++) {
		if (freq.size() == 0 || tangerine[i] != freq[freq.size()-1].size) {
			freq.push_back({ tangerine[i], 1 });
		}
		else {
			freq[freq.size()-1].cnt++;
		}
	}
	sort(freq.begin(), freq.end(), chk);
	for (int i = 0; i < freq.size(); i++) {
		if (k > 0) {
			answer++;
			k -= freq[i].cnt;
		}
		else {
			return answer;
			break;
		}
	}
}
