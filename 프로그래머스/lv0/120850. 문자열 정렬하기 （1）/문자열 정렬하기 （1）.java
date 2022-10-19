import java.util.*;

class Solution {
    public int[] solution(String my_string) {
        List<Integer> nums = new ArrayList<Integer>();
        for(int i=0;i<my_string.length();i++){
            if(my_string.charAt(i) <= '9')
                nums.add(my_string.charAt(i) - '0');
        }
        Collections.sort(nums);
        
        return nums.stream().mapToInt(Integer::intValue).toArray();
    }
}