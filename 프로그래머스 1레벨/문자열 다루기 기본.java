class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        try {
            int a = Integer.valueOf(s);
        } catch (NumberFormatException e) {
            answer = false;
        }
        if (s.length() != 4 && s.length() != 6) {
            answer = false;
        }
        return answer;
    }
}
