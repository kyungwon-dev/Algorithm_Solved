import java.util.*;

class Solution {
    public int[] solution(String[] intStrs, int k, int s, int l) {
        List<Integer> answer = new ArrayList<Integer>();
        for(String str : intStrs){
            int num = Integer.valueOf(str.substring(s, s+l));
            if( num > k)
                answer.add(num);
        }

        return answer.stream().mapToInt(i->i).toArray();
    }
}