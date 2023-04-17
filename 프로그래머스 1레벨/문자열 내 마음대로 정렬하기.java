import java.util.Arrays;
class Solution {
    public String[] solution(String[] strings, int n) {
        int l = strings.length;
        String[] arr = new String[l];
        for (int i = 0; i < l; i++) {
            arr[i] = strings[i].substring(n,n+1);
        }
        Arrays.sort(strings);
        Arrays.sort(arr);
        String[] answer = new String[l];
        for (int i = 0; i < l; i++) {
            System.out.print(arr[i]);
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (arr[i].equals(strings[j].substring(n,n+1))) {
                    answer[i] = strings[j];
                    strings[j] = "****************************************************************************************************";
                    break;
                }
            }
        }
        
        return answer;
    }
}
