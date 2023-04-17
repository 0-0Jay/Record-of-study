import java.util.*;
class Solution
{
    public int solution(int []A, int []B)
    {
        int n = B.length;
        int sum = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        for (int i : A) {
            sum += i * B[--n];
        }
        return sum;
    }
}
