import java.util.Arrays;
class Solution {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        int first = 0;
        int last = people.length;
        int answer = 0;
        
        while (first < last) {
        	int a = people[first];
        	int b = people[last-1];
            if (a + b > limit) {
                last--;
                answer++;
            } else if (a + b <= limit) {
                first++;
                last--;
                answer++;
            }
        }
        return answer;
    }
}
