import java.util.*;

class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        Map<String, String> map = new HashMap<String,String>(){{
            put("aya","0");
            put("ye","1");
            put("woo","2");
            put("ma","3");
        }};
        for(String bab : babbling){
            boolean isPossible = true;
            for(Map.Entry<String,String> set : map.entrySet()){
                bab = bab.replace(set.getKey(),set.getValue());
            }
            for(int i=0;i<bab.length();i++){
                if(i==0){
                    if(bab.charAt(i) > '3' || bab.charAt(i) < '0'){
                        isPossible = false;
                        break;
                    }        
                }
                else{
                    if(bab.charAt(i) > '3' || bab.charAt(i) < '0'){
                        isPossible = false;
                        break;
                    }
                    else if(bab.charAt(i-1) == bab.charAt(i)){
                        isPossible = false;
                        break;
                    }
                }
            }
            if(isPossible){
                answer++;
            }
        }
        
        return answer;
    }
}