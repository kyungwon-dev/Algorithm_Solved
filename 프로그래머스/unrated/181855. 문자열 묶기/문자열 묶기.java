import java.util.*;

class Solution {
    public int solution(String[] strArr) {
        int answer = 0;
        int[] nums = new int[100000];
        for(String str : strArr){
            nums[str.length()]++;
        }
        
        return Arrays.stream(nums).max().getAsInt();
    }
}