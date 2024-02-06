import java.util.*;

class Solution {
    public int[] solution(int l, int r) {
        List<Integer> answer = new ArrayList<Integer>();
        
        for(int i=1;i<64;i++){
            int num = Integer.valueOf(Integer.toBinaryString(i)) * 5;
            if(num >= l && num <= r)
                answer.add(num);
        }
        if(answer.size()==0) answer.add(-1);
        return answer.stream().mapToInt(i->i).toArray();
    }
}