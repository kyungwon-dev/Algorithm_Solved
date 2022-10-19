import java.util.*;

class Solution {
    public int[] solution(int n, int[] numlist) {
        List<Integer> nums = new ArrayList<Integer>();
        for(int num : numlist){
            if(num%n == 0)
                nums.add(num);
        }
        return nums.stream().mapToInt(Integer::intValue).toArray();
    }
}