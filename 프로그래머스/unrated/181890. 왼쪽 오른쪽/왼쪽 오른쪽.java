import java.util.*;

class Solution {
    public String[] solution(String[] str_list) {
        String[] answer = new String[1];
        for(int i=0;i<str_list.length;i++){
            if("r".equals(str_list[i])){
                answer = new String[str_list.length - i - 1];
                for(int j=i+1;j<str_list.length;j++){
                    answer[j-i-1] = str_list[j];
                }
                return answer;
            } else if("l".equals(str_list[i])){
                answer = new String[i];
                for(int j=0;j<i;j++){
                    answer[j] = str_list[j];
                }
                return answer;
            }
        }
        return new String[0];
    }
}