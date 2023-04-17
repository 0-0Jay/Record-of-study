class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        for (int i = 0; i < t.length() - p.length() + 1; i++) {
            String num = t.substring(i,i + p.length());
            if (Long.parseLong(p) >= Long.parseLong(num)) {
                answer++;
            }
        }
        return answer;
    }
}
