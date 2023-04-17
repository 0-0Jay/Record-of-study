class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int size = nums.length;
        int[] prime = new int[3001];
        prime[0] = 2;
        prime[1] = 2;
        for (int i = 0; i <= 3000; i++) {
            prime[i] = 0;
        }
        for (int i = 2; i <= 3000; i++) {
            for (int j = i; j <= 3000; j += i) {
                prime[j]++;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    int n = nums[i] + nums[j] + nums[k];
                    if (prime[n] <= 1) {
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
}
