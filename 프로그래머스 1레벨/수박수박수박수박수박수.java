class Solution {
    public String solution(int n) {
        String ans = "";
        for (int i = 1; i <= n; i++) {
            ans += (i % 2 == 0)? "박":"수";
        }
        return ans;
    }
}
