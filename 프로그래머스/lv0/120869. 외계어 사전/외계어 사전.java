import java.util.*;

class Solution {
    public int solution(String[] spell, String[] dic) {
        
        Arrays.sort(spell);
        String spells = "";
        for(int i=0;i<spell.length;i++)
            spells += spell[i];
        for(int i=0;i<dic.length;i++){
            char[] tmp = dic[i].toCharArray();
            Arrays.sort(tmp);
            String rs = new String(tmp);
            if(spells.equals(rs)){
                
                return 1;
            }
        }
        return 2;
    }
}