import java.util.HashMap;
import java.util.Map;
import java.util.stream.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        HashMap<String, Integer> want_map = new HashMap<String, Integer>(10);
        for(String w : want){
            want_map.put(w,0);
        }
        for(int i=0;i<10;i++){
            if(want_map.containsKey(discount[i])){
                want_map.put(discount[i],want_map.get(discount[i])+1);
            }
        }
        int idx = 0, answer =0;
        boolean is_join = true;
        for(int i=0;i<want.length;i++){
            int cnt = want_map.get(want[i]);
            if(cnt < number[i]){
                is_join = false;
                break;
            }
        }
        if(is_join) answer++;
        while(idx < discount.length-10){    
            if(want_map.containsKey(discount[idx]))
                want_map.put(discount[idx],want_map.get(discount[idx])-1);
            if(want_map.containsKey(discount[idx+10]))
                want_map.put(discount[idx+10],want_map.get(discount[idx+10])+1);
            idx++;
            is_join = true;
            for(int i=0;i<want.length;i++){
                int cnt = want_map.get(want[i]);
                if(cnt != number[i]){
                    is_join = false;
                    break;
                }
            }
            if(is_join){
                answer++;
            }
        }
        return answer;
    }
}