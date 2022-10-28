import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        List<String> nums = new ArrayList<String>();
        String[] cmds = s.split(" ");
        for(int i=0;i<cmds.length;i++){
            if(cmds[i].equals("Z")){
                if(nums.isEmpty()) continue;
                nums.remove(nums.size()-1);
            }
            else{
                nums.add(cmds[i]);
            }   
        }
        for(String num : nums){
            answer += Integer.parseInt(num);
        }
        return answer;
    }
}