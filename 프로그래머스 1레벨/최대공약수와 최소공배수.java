class Solution {
    public int[] solution(int n, int m) {
        int[] answer = {0,0};
        int r;
        answer[0] = (n > m)? n:m;
        int b = (n > m)? m:n;
        
        while (b != 0) {
            r = answer[0] % b;
            answer[0] = b;
            b = r;
        }
        answer[1] = n * m / answer[0];
        return answer;
    }
}
