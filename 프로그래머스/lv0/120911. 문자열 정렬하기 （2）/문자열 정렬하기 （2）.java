import java.util.*;

class Solution {
    public String solution(String my_string) {
        String answer = "";
        my_string = my_string.toLowerCase();
        char[] chars = my_string.toCharArray();
        
        Arrays.sort(chars);
        answer = String.valueOf(chars);
        return answer;
    }
}