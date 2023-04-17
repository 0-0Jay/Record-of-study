import java.util.ArrayList;
class Solution {
    public int[] solution(int brown, int yellow) {
        ArrayList<Integer> arr = new ArrayList<>();
        int v = brown + yellow;
        for (int i = 1; i <= v; i++) {
            if (v % i == 0) {
                arr.add(i);
            }
        }
        int n = arr.size();
        int[] answer = {0,0};
        if (n % 2 == 0) {
            for (int i = 0; i < n/2; i++) {
                answer[0] = arr.get(n/2 + i);
                answer[1] = arr.get(n/2-1 - i);
                if ((answer[0]-2)*(answer[1]-2) == yellow) {
                    break;
                }
            }
        } else {
            for (int i = 0; i < n/2; i++) {
                answer[0] = arr.get(n/2 + i);
                answer[1] = arr.get(n/2 - i);
                if ((answer[1]-2)*(answer[0]-2) == yellow) {
                    break;
                }
            }
        }
        return answer;
    }
}
