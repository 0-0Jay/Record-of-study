class Solution {
    public int solution(int n) {
        int i = 1;
        for (i = 1; i < n; i++) {
            if (n % i == 1) {
                break;
            }
        }
        int answer = i;
        return answer;
    }
}
