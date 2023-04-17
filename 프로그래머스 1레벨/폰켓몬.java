import java.util.HashSet;
class Solution {
    public int solution(int[] nums) {
        HashSet<Integer> arr = new HashSet<>();
        for (int i = 1; i < nums.length; i++) {
            arr.add(nums[i]);
        }
        int answer = 0;
        if (arr.size() >= nums.length / 2) {
            answer = nums.length / 2;
        } else {
            answer = arr.size();
        }
        return answer;
    }
}
