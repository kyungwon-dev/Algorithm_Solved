import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int minValue = Integer.MAX_VALUE;
        int maxValue = Integer.MIN_VALUE;
        List<Integer> answer = new ArrayList<Integer>();
        
        for(int i=0;i<arr.length;i++){
            if(arr[i] == 2){
                minValue = Math.min(minValue, i);
                maxValue = Math.max(maxValue, i);
            }
        }
        
        while(minValue <= maxValue){
            answer.add(arr[minValue]);
            minValue++;
        }
        if(answer.size() == 0)
            answer.add(-1);
        return answer.stream().mapToInt(i->i).toArray();
    }
}