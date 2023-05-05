import java.util.*;
import java.util.stream.*;

class Solution {

    
    public String[] solution(String[] players, String[] callings) {
        Map<String, Integer> p2r = new HashMap<String, Integer>();
        Map<Integer, String > r2p = new HashMap<Integer, String>();
        final int isChange = 50001;
        for(int i=0;i<players.length;i++){
            p2r.put(players[i], i);
            r2p.put(i, players[i]);
        }
        
        for(int i=0;i<callings.length;i++){
            int up = p2r.get(callings[i]);
            String down = r2p.get(up-1);
            p2r.put(callings[i], up-1);
            p2r.put(down, up);
            
            r2p.put(up-1, callings[i]);
            r2p.put(up, down);
            
        }
      
        String[] answer = new String[players.length];
        for(int i=0;i<players.length;i++){
            answer[i] = r2p.get(i);
        }
        
        return answer;
    }
}