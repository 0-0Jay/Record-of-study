class Solution {
    public String solution(String[] seoul) {
        int i = 0;
        for (i = 0; i < seoul.length; i++) {
            if (seoul[i].equals("Kim")) {
                break;
            }
        }
        String answer = String.format("김서방은 %d에 있다",i);
        return answer;
    }
}
