import java.util.*;

class Solution {
    public int[] solution(int start_num, int end_num) {
        List<Integer> arr = new ArrayList<Integer>();
        for(int i=start_num;i<=end_num;i++) arr.add(i);
        return arr.stream()
                .mapToInt(i -> i)
                .toArray();
    }
}