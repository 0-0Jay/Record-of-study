class Solution {
    public String solution(String s, int n) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        String A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String answer = "";
        int x = a.length();
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < x; j++) {
                if (s.charAt(i) != ' ') {
                    if (s.charAt(i) == a.charAt(j)) {
                        if (j + n >= 26) {
                            answer += String.valueOf(a.charAt(j+n-26));
                            break;
                        } else {
                            answer += String.valueOf(a.charAt(j+n));
                            break;
                        }
                    } 
                    if (s.charAt(i) == A.charAt(j)) {
                        if (j + n >= 26) {
                            answer += String.valueOf(A.charAt(j+n-26));
                            break;
                        } else {
                            answer += String.valueOf(A.charAt(j+n));
                            break;
                        }
                    }
                } else {
                    answer += " ";
                    break;
                }
            }
        }
        
        return answer;
    }
}
