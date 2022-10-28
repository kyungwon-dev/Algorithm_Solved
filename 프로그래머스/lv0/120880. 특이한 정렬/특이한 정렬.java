import java.util.*;
import java.math.*;

class Solution {
    public int[] solution(int[] numlist, int n) {
        int[] answer = {};
        Integer[] numInt = Arrays.stream(numlist).boxed().toArray(Integer[]::new);
        Arrays.sort(numInt, (a,b) -> Math.abs(n-a) - Math.abs(n-b) == 0? b-a : Math.abs(n-a) - Math.abs(n-b));
        
        return Arrays.stream(numInt).mapToInt(i->i).toArray();
    }
}