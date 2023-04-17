class Solution {
    public int solution(int n) {
        String a = Integer.toString(n,3);
        String b = "";
        for (int i = a.length()-1;i >=0; i--) {
            b += String.valueOf(a.charAt(i));
        }
        int answer = Integer.parseInt(b,3);
        return answer;
    }
}
