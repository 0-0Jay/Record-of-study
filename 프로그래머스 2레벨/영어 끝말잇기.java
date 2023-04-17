import java.util.ArrayList;
class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {0,0};
        ArrayList<String> arr = new ArrayList<>();
        boolean noLose = true;
        
        for (int i = 0 ; i < words.length; i++) {
            if (arr.contains(words[i])) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                noLose = false;
                break;
            }
            arr.add(words[i]);
            if (i > 0) {
                if (words[i].charAt(0) != words[i-1].charAt(words[i-1].length()-1)) {
                    answer[0] = i % n + 1;
                    answer[1] = i / n + 1;
                    noLose = false;
                    break;
                }
            }
        }
        if (noLose) {
            answer[0] = 0;
            answer[1] = 0;
        }
        
        return answer;
    }
}
