// 프로그래머스 다트 게임 : https://school.programmers.co.kr/learn/courses/30/lessons/17682

import java.util.*;
class Solution {
    public int solution(String dartResult) {
        int n = -1;
        int[] arr = new int [4];  // arr에 숫자 저장, char에 따라 배열에서 연산 결과 저장
        int answer = 0;
        for (int i = 0; i < dartResult.length(); i++) {
            char now = dartResult.charAt(i);
            if (now >= '0' && now <= '9') {
                if (i > 0 && dartResult.charAt(i - 1) == '1') n--;
                arr[++n] = arr[n] * 10 + (now - '0');
            } else if (now == 'D') {
                arr[n] = (int)Math.pow(arr[n], 2);
            } else if (now == 'T') {
                arr[n] = (int)Math.pow(arr[n], 3);
            } else if (now == '*') {
                arr[n] *= 2;
                if (n - 1 >= 0) arr[n - 1] *= 2;
            } else if (now == '#') {
                arr[n] *= -1;
            }
        }
        for (int i = 0; i < 3; i++) {
            answer += arr[i];  // 최종적으로 배열에 들어있는 결과값의 총 합 반환
        }
        return answer;
    }
}
