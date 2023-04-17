class Solution {
    public long solution(int price, int money, int count) {
        long answer = 0;
        for (int i = count; i > 0; i--) {
            answer += price * i;
        }
        answer -= (answer > money)? money:answer;
        return answer;
    }
}
