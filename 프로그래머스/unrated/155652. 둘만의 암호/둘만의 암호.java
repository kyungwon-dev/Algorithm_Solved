import java.util.*;

class Solution {
    
    boolean[] isSkip = new boolean[26];
    
    public String solution(String s, String skip, int index) {
        String answer = "";
        for(int i=0;i<skip.length();i++){
            isSkip[skip.charAt(i) - 'a'] = true;
        }
        
        for(int i=0;i<s.length();i++){
            int plus = 0, idx = 0;
            while(idx < index){
                plus++;

                if(isSkip[ (s.charAt(i) - 'a' + plus) % 26] == false){
                    idx++;
                }         
            }
            answer += (char)  ( (s.charAt(i) - 'a' + plus) % 26 + 'a' );
        }
        
        return answer;
    }
}