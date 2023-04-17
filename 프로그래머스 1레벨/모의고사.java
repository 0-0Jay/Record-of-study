import java.util.ArrayList;
class Solution {
    public int[] solution(int[] answers) {
        int size = answers.length;
        int[] correct = {0, 0, 0};
        int[] two = {1, 3, 4, 5};
        int[] three = {3, 1, 2, 4, 5};
        for (int i = 0; i < size; i++) {
            int a = (i % 5) + 1;
            int b = (i % 2 == 0)? 2:two[(i%8)/2];
            int c = three[i%10/2];
            
            if (answers[i] == a) {
                correct[0]++;
            } 
            if (answers[i] == b) {
                correct[1]++; 
            } 
            if (answers[i] == c) {
                correct[2]++;
            }
        }
        int max = 0;
        for (int i : correct) {
            if (max < i) {
                max = i;
            }
        }
        int count = 0;
        String ans = "";
        for (int i = 0; i < correct.length; i++) {
            if (max == correct[i]) {
                count++;
                ans += Integer.toString(i);
            }
        }
        int[] answer = new int[count];
        for (int i = 0; i < count; i++) {
            answer[i] = ans.charAt(i)-47;
        }
        return answer;
    }
}
