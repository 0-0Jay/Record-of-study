import java.util.*;
class Solution {
    public int[] solution(int[] arr, int d) {
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (int i : arr) {
             if (i % d == 0) {
                 a.add(i);
             }
        }
        if (a.size() == 0) {
            a.add(-1);
        }
        int[] answer = new int[a.size()];
        for (int i = 0; i < a.size(); i++) {
            answer[i] = a.get(i);
        }
        Arrays.sort(answer);
        return answer;
    }
}
