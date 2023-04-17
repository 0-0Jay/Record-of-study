import java.util.Arrays;
class Solution {
    public int solution(int[][] sizes) {
        int w = 0;
        int h = 0;
        int l = sizes.length;
        for (int i = 0; i < l; i++) {
            Arrays.sort(sizes[i]);
            h = (h < sizes[i][0])? sizes[i][0]:h;
            w = (w < sizes[i][1])? sizes[i][1]:w;
        }        
        int answer = h*w;
        return answer;
    }
}
