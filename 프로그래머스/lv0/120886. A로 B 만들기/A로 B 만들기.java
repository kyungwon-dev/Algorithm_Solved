import java.util.*;

class Solution {
    public int solution(String before, String after) {
        char[] tmp;
        tmp = before.toCharArray();
        Arrays.sort(tmp);
        before = String.valueOf(tmp);
        tmp = after.toCharArray();
        Arrays.sort(tmp);
        after = String.valueOf(tmp);
        
        
        return before.equals(after) == true ? 1 : 0;
    }
}