import java.util.*;

class Solution {
    public String solution(String myString) {
        String answer = "";
        char[] myChar = myString.toCharArray();
        for(int i=0;i<myChar.length;i++){
            if(myChar[i] == 'a') myChar[i] = 'A';
            else if(myChar[i] == 'A') continue;
            else myChar[i] = Character.toLowerCase(myChar[i]);
        }
        return String.valueOf(myChar);
    }
}