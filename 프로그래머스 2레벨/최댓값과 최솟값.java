import java.util.*;
class Solution {
    public String solution(String s) {
        String arr[] = s.split(" ");
        int[] num = new int[arr.length];
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(arr[i]);
        }
        Arrays.sort(num);
        String answer = Integer.toString(num[0]) + " "+ Integer.toString(num[n-1]);   
        return answer;
    }
}
