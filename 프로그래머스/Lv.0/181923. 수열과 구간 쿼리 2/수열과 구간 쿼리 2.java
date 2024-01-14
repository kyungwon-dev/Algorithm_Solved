import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        List<Integer> answer = new ArrayList<Integer>();
        for(int i =0;i <queries.length;i++){
            int num = 1000001;
            for(int j=queries[i][0]; j<= queries[i][1]; j++){
                if(arr[j] > queries[i][2]){
                    num = Math.min(arr[j], num);
                }
            }
            
            if(num == 1000001){
                answer.add(-1);    
            }else{
                answer.add(num);    
            }
            
        }
        return answer.stream().mapToInt(i->i).toArray();
    }
}