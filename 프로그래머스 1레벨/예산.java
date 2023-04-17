import java.util.Arrays;
class Solution {
    public int solution(int[] d, int b) {
        Arrays.sort(d);
        int answer = 0;
        for (int i : d) {
            if (b - i < 0) break;
            b -= i;
            answer++;
        }
        return answer;
    }
}
