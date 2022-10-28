import java.math.*;

class Solution {
    public int solution(int[] sides) {
        int answer = 0;
        // 가장 긴 변
        int longest = sides[0] > sides[1] ? sides[0] : sides[1];
        int mid = sides[0] > sides[1] ? sides[1] : sides[0];
        for(int i=1; i< longest; i++){
            if(i+mid > longest){
                answer++;
            } 
        }
        //
        for(int i=longest; i< longest+mid; i++){
            if(mid+longest > i) {
                answer++;
            }
        }
        return answer;
    }
}