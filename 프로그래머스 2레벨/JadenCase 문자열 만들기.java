class Solution {
    public String solution(String s) {
        String answer = "";
        String[] arr = s.toLowerCase().split("");
        boolean t = true;
        for (String i : arr) {
            answer += t ? i.toUpperCase():i;
            t = (i.equals(" ")) ? true:false;
        }
        return answer;
    }
}
