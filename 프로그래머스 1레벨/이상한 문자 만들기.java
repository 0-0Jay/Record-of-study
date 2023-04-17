class Solution {
    public String solution(String s) {
        String answer = "";
        String[] f = s.split("");
        for (int i = 0; i < f.length; i++) {
            if(f[i] ==" ") {
                answer += " ";
            } else {
                break;
            }
        }
        String[] word = s.split(" ");
        for(int i = 0; i < word.length; i++) {
            String[] arr = word[i].split("");
            for(int j = 0; j < arr.length; j++) {
                answer += (j % 2 == 0)? arr[j] = arr[j].toUpperCase():arr[j].toLowerCase();
            }
            if (i != word.length - 1){
                answer += " ";
            }
        }
        for (int i = f.length-1; i >= 0; i--) {
            if (f[i].equals(" ")) {
                answer += " ";
            } else {
                break;
            }
        }
        return answer;
    }
}
