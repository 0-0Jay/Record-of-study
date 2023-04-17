class Solution {
    public int solution(int num) {
        int count = 0;
        long x = (long)num;
        while (x != 1) {
            if (x == 1) {
                break;
            } else {
                x = (x % 2 == 0)? x/2:(x*3)+1;
                count++;
                if (count == 500) {
                    break;
                }
            }
        }
        int answer = -1;
        if (count < 500) {
            answer = count;
        }
        return answer;
    }
}
