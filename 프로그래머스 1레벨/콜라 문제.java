class Solution {
    public int solution(int a, int b, int n) {
        // a = 교환에 필요한 수, b = 교환시 주는 콜라 수, n = 가진 콜라 수
        int answer = 0;
        while (n >= a) {
            answer += n / a * b;
            n = ((n / a) * b) + (n % a);
        }
        return answer;
    }
}
