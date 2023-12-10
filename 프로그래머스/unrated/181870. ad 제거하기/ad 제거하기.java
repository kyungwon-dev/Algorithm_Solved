import java.util.*;

class Solution {
    public String[] solution(String[] strArr) {
        List<String> answer = new ArrayList<String>();
        for(String str : strArr){
            if(str.indexOf("ad") == -1)
                answer.add(str);
        }
        return answer.toArray(new String[answer.size()]);
    }
}