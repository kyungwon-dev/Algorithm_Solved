import java.util.*;


class Solution {
    public int[] solution(int n) {
        List<Integer> nums = new ArrayList<Integer>();
        int md = 2;
        while(md <= n){
            if(n % md == 0){
                nums.add(md);
                n = n/ md;
            }
            else{
                md++;
            }
        }
        if(nums.size() == 0){
            nums.add(n);
        }
        Set<Integer> s = new HashSet<Integer>(nums);
        List<Integer> answer = new ArrayList<Integer>(s);
        Collections.sort(answer);
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}