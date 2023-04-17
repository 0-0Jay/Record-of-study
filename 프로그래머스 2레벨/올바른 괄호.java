class Solution {
    boolean solution(String s) {
        boolean answer = true;
        char[] arr = s.toCharArray();
        int ac = 0;
        int bc = 0;
        for (char i : arr) {
            if (i == '(') {ac++;} else {bc++;}
            if (ac > 0) {
                if (ac < bc) {
                    answer = false;
                    break;
                } else {
                    answer = true;
                }
            } else {
                answer = false;
                break;
            }
            if (ac == bc) {
                answer = true;
            } else {
                answer = false;
            }
        }
        return answer;
    }
}
