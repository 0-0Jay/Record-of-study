class Solution {
    boolean solution(String s) {
        int p = 0,y = 0,x = s.length();
        char[] arr = new char[x];
        for (int i = 0; i < x; i++) {
            arr[i] = s.charAt(i);
            p += ((arr[i]=='p')||(arr[i]=='P'))? 1:0;
            y += ((arr[i]=='y')||(arr[i]=='Y'))? 1:0;
        }  
        return (p == y);
    }
}
