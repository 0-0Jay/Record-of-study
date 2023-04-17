import java.util.Arrays;
class Solution {
    public static int[] solution(int[] numbers) {
        int[] result = new int[200];
        int index = 0;
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i+1; j < numbers.length; j++) {
                boolean dup = false;
                for (int k = 0; k < index; k++) {
                    if (result[k] == numbers[i] + numbers[j]) {
                        dup = true;
                        break;
                    }
                }
                if (dup == false) {
                    result[index] = numbers[i] + numbers[j];
                    index++;
                }
            }
        }
        int[] answer = new int[index];
        for (int i = 0; i < index; i++) {
            answer[i] = result[i];
        }
        Arrays.sort(answer);
        return answer;
    }
}
