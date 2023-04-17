class Solution {
    public boolean solution(int x) {
        int sum = 0;
        int a = x;
        while (a != 0) {
            sum += a % 10;
            a/=10;
        }
        boolean answer = (x % sum == 0)? true:false;
        return answer;
    }
}
