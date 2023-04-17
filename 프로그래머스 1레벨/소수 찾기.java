class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] arr = new int[n+1];
        for (int i = 0; i <= n; i++) {
            arr[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                arr[j]++;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (arr[i] == 1) {
                answer++;
            }
        }
            
        return answer;
    }
}
