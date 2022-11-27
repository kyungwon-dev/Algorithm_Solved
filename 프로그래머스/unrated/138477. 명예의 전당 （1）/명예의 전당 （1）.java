import java.util.*;

class Solution {
    public int[] solution(int k, int[] scores) {
        List<Integer> nums = new ArrayList<Integer>();
        List<Integer> honor = new ArrayList<Integer>();
        for(int score : scores){
            honor.add(score);
            Collections.sort(honor);
            
            if(honor.size() > k)
                honor.remove(0);
            
            nums.add(honor.get(0));
        }
        int[] answer = nums.stream().mapToInt(i->i).toArray();
        return answer;
    }
}