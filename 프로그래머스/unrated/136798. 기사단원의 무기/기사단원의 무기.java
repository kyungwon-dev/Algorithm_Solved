import java.util.*;

class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for(int i=1;i<=number;i++){
            int mul = 2, num = i, idx=0, tot=1;
            boolean isCalc = false;
            List<Integer> nums = new ArrayList<Integer>();
            nums.add(1);
            while(num != 1){
                if( num % mul == 0){
                    nums.set(idx, nums.get(idx) + 1);
                    num /= mul;
                }
                else{
                    mul++;
                    if(num % mul != 0) continue;
                    tot *= nums.get(idx);
                    idx++;
                    nums.add(1);
                }
                if(tot > limit){
                    tot = power;
                    isCalc = true;
                    break;
                }
            }
            
            tot *= nums.get(idx);
            if(tot > limit)
                tot = power;
            answer += tot;
        }
        
        return answer;
    }
}