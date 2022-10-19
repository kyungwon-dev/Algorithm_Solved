import java.util.*;

class Solution {
    public int[] solution(int n) {
        List<Integer> nums = new ArrayList<Integer>();
        for(int i=1;i<=n;i++){
            if(n%i == 0){
                nums.add(i);
            }
        }
        int[] answer = nums.stream().mapToInt(Integer::intValue).toArray();
        Arrays.sort(answer);
        
        return answer;
    }
}