import java.util.*;

class Solution {
    public String[] solution(String myString) {
        List<String> answer = new ArrayList<String>();
        for(String str : myString.split("[x]+")){
            if(str.length() == 0) continue;
            answer.add(str);
        }
        Collections.sort(answer);
        return answer.toArray(new String[answer.size()]);
    }
}