class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];
        while(!s.equals("1")){
            answer[0]++;
            int count = 0;
            String[] arr = s.split("");
            for (int i = 0; i < arr.length; i++) {
                int a = (arr[i].equals("1"))? count++:answer[1]++;
            }
            s = Integer.toBinaryString(count);
        }
        
        return answer;
    }
}
