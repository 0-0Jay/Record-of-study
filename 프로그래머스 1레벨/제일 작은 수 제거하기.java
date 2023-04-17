import java.util.ArrayList;
class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            al.add(arr[i]);
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        al.remove(al.indexOf(min));
        if (al.size() == 0) {
            al.add(-1);
        }
        int[] answer = new int[al.size()];
        for (int i = 0; i < al.size(); i++) {
            answer[i] = al.get(i);
        }
        return answer;
    }
}
