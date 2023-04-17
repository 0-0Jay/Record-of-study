import java.util.Stack;
class Solution
{
    public int solution(String s)
    {
        Stack<Character> arr = new Stack<>();
        int answer = 1;
        for (int i = 0; i < s.length(); i++) {
            if (arr.empty()) {
                arr.push(s.charAt(i));
            } else {
                if (arr.peek() == s.charAt(i)) {
                    arr.pop();
                } else {
                    arr.push(s.charAt(i));
                }
            }
            if (arr.empty()) {
                answer = 1;
            } else {
                answer = 0;
            }
        }
        return answer;
    }
}
