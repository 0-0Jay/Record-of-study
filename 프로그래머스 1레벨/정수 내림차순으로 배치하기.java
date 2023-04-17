import java.util.*;
class Solution {
    public long solution(long n) {
        String[] arr = (Long.toString(n)).split("");
        Arrays.sort(arr);
        long answer = 0;
        for (int i = 0; i < arr.length; i++) {
            answer += Integer.valueOf(arr[i]) * (Math.pow(10,i));
        }
        return answer;
    }
}
