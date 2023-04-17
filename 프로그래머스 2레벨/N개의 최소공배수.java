import java.util.Arrays;
class Solution {
    public int solution(int[] arr) {
        Arrays.sort(arr);
        for (int i = arr.length-1; i > 0; i--) {
            int x = arr[i], y = arr[i-1],r;
            while (y != 0) {
                r = x % y;
                x = y;
                y = r;
            }
            arr[i-1] *= arr[i] / x;
        }
        int answer = arr[0];
        return answer;
    }
}
