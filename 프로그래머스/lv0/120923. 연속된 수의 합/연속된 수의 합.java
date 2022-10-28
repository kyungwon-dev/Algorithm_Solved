import java.util.*;

class Solution {
    public int[] solution(int num, int total) {
        List<Integer> answer = new ArrayList<Integer>();
        for(int i=(-1000);i<=1000;i++){
            int sub_total = (i*num) + ((num) * (num-1) / 2);
            if(sub_total == total){
                for(int j=i;j<i+num;j++)
                    answer.add(j);
                System.out.println(answer);
                break;
            }
            
        }
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}