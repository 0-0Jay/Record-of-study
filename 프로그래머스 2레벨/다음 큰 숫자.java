class Solution {
    public int solution(int n) {
		int countn = 0;   
		int countm = 0;
        String x = Integer.toBinaryString(n);
        char[] narr = x.toCharArray();
        for (char i : narr) {
            countn += (i == '1')? 1:0;
        }
        int m = n;
        while (countn != countm) {
            countm = 0;
            m++;
            String y = Integer.toBinaryString(m);
            char[] marr = y.toCharArray();
            for (char i : marr) {
                countm += (i == '1')? 1:0;;
            }
        }
        int answer = m;
        return answer;
    }
}
