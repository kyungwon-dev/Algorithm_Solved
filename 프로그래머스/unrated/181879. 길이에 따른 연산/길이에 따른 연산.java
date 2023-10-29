import java.util.*;

class Solution {
    public int solution(int[] num_list) {
        int answer = 1;
        if(num_list.length <= 10){
            for(int num: num_list){
                answer *= num;
            }
            return answer;
        }
        return Arrays.stream(num_list).sum();
    }
}