import java.util.LinkedList;
class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        LinkedList<String> cache = new LinkedList<>();
        for (String i : cities) {
            if (cacheSize == 0) {
                answer = cities.length * 5;
                break;
            }
            i = i.toLowerCase();
            for (int j = 0 ; j < cacheSize; j++) {
                if (cache.indexOf(i) == -1) {
                    if (cache.size() < cacheSize) {
                        cache.add(i);
                    } else {
                        cache.removeFirst();
                        cache.add(i);
                    }
                    answer += 5;
                    break;
                } else {
                    cache.remove(i);
                    cache.add(i);
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
}
