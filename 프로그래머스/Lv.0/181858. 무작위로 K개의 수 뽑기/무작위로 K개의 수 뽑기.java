import java.util.*;

class Solution {
    public int[] solution(int[] arr, int k) {
        List<Integer> answer = new ArrayList<Integer>();       
        boolean[] nums = new boolean[100001];
        for(int i=0;i<arr.length;i++){
            if(nums[arr[i]]) continue;
            nums[arr[i]] = true;
            answer.add(arr[i]);
            k--;
            if(k==0) break;
        }
        for(int i=0;i<k;i++)
            answer.add(-1);
        return answer.stream().mapToInt(i->i).toArray();
    }
}