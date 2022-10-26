import java.util.Arrays;

class Solution {
    public int[] solution(int[] emergency) {
        int[] answer = new int[emergency.length];
        int[] idx = new int[emergency.length];
        for(int i=0;i<emergency.length;i++){
            answer[i] = i+1;
            idx[i] = emergency[i];
        }
        Arrays.sort(emergency);
        for(int i=0;i<emergency.length;i++){
            for(int j=0;j<emergency.length;j++){
                if(emergency[j] == idx[i]){
                    answer[i] = emergency.length - j;
                    break;
                }
            }
            
        }
        
        
        return answer;
    }
}