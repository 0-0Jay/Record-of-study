class Solution {
    public long solution(long n) {
        double a = Math.pow(n,0.5);
        long answer = (a == (long) a)? (long)Math.pow(a+1,2):-1;
        return answer;
    }
}
