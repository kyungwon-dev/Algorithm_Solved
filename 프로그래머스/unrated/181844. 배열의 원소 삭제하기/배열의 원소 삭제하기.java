import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        List<Integer> answer = new ArrayList<Integer>();
        for(int a : arr){
            boolean isCheck = true;
            for(int d : delete_list){
                if( a== d){
                    isCheck = false;
                    break;
                }
            }
            if(isCheck){
                answer.add(a);
            }
        }
        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}