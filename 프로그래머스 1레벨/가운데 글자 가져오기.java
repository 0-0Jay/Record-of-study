class Solution {
    public String solution(String s) {
        String answer = "";
        int n = s.length();
        if (s.length() % 2 == 0) {
            answer += s.substring(n/2-1, n/2+1);
        } else {
            answer += s.substring(n/2, n/2+1);
        }
        return answer;
    }
}
