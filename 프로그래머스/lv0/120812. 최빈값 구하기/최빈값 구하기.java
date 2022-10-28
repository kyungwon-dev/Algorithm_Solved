class Solution {
    public int solution(int[] array) {
        int[] nums = new int[1000];
        for(int i=0;i<array.length;i++){
            nums[array[i]]++;
        }
        int answer = 0, cnt=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i] > cnt){
                cnt = nums[i];
                answer = i;
            }
                
            else if(nums[i] == cnt){
                cnt =0;
                answer = 0;
            }
                
        }
        if(cnt == 0) answer--;
        return answer;
    }
}