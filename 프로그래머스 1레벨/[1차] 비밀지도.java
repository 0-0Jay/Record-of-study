class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        for (int i = 0; i < n; i++) {
            int x = arr1[i] | arr2[i];
            answer[i] = "";
            char[] s = (Integer.toString(x,2)).toCharArray();
            int l = s.length;
            while (n-l > answer[i].length()) {
                answer[i] += " ";
            }
            for (int j = 0; j < l; j++) {
                if (s[j] == '1') {
                    answer[i] += "#";
                } else {
                    answer[i] += " ";
                }
            }    
            
        }
        return answer;
    }
}
