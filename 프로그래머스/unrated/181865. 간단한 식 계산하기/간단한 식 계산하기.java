class Solution {
    public int solution(String binomial) {
        int answer = 0;
        String[] nums = binomial.split(" ");
        if("+".equals(nums[1])){
            answer = Integer.valueOf(nums[0]) +  Integer.valueOf(nums[2]);
        }else if("-".equals(nums[1])){
            answer = Integer.valueOf(nums[0]) -  Integer.valueOf(nums[2]);
        }else{
            answer = Integer.valueOf(nums[0]) *  Integer.valueOf(nums[2]);
        }
        return answer;
    }
}