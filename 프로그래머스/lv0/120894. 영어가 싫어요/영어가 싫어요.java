import java.util.*;

class Solution {
    public long solution(String numbers) {
        long answer = 0;
        Map<String,String> nums = new HashMap<String,String>(){{
            put("zero","0");
            put("one","1");
            put("two","2");
            put("three","3");
            put("four","4");
            put("five","5");
            put("six","6");
            put("seven","7");
            put("eight","8");
            put("nine","9");
        }};
        for(Map.Entry<String, String> entry : nums.entrySet()){
            numbers = numbers.replace(entry.getKey(), entry.getValue());
        }
        answer = Long.parseLong(numbers);
        
        return answer;
    }
}