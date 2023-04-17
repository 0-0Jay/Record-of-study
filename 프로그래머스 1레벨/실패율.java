import java.util.Arrays;
class Solution {
    public int[] solution(int N, int[] stages) {
        int[] clear = new int[N+1];
        int[] arrive = new int[N+2];
        for (int i = 0; i < clear.length; i++) {
            clear[i] = 0;
        }
        for (int i : stages) {
            for (int j = 1; j < i; j++) {
                clear[j]++;
            }
        }
        for (int i : stages) {
            for (int j = 1; j <= i; j++) {
                arrive[j]++;
            }
        }
        double[] fail = new double[N];
        double[] temp = new double[N];
        for (int i = 0; i < N; i++) {
            if (arrive[i+1] != 0) {
                fail[i] = 1 - ((double)clear[i+1]/arrive[i+1]);
                temp[i] = fail[i];
            } else {
                fail[i] = 0;
                temp[i] = 0;
            }
        }
        Arrays.sort(temp);
        int[] answer = new int[N];
        int index = 0;
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (temp[i] == fail[j]) {
                    answer[index] = j+1;
                    fail[j] = -1;
                    index++;
                }
            }
        }
        return answer;
    }
}
