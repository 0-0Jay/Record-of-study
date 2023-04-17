class Solution {
    public int solution(int n) {
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                sum += (i + j);
                if (sum == n) {
                    sum = 0;
                    count++;
                    break;
                } else if (sum > n) {
                    sum = 0;
                    break;
                }
            }
        }
        return count;
    }
}
