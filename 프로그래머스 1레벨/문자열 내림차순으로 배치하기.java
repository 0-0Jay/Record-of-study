import java.util.*;
class Solution {
    public String solution(String s) {
        String[] arr = s.split("");
        Arrays.sort(arr,Collections.reverseOrder());
        String answer = "";
        for (String i : arr) {
            answer += i;
        }
        return answer;
    }
}
