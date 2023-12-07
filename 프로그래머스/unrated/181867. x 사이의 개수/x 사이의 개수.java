import java.util.*;

class Solution {
    public int[] solution(String myString) {
        List<Integer> answer = new ArrayList<Integer>();
        String[] rs = myString.split("x");
        for(String s : rs){
            answer.add(s.length());
        }
        if(myString.charAt(myString.length()-1) == 'x')
            answer.add(0);
        return answer.stream().mapToInt(i->i).toArray();
    }
}