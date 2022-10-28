import java.util.*;

class Solution {
    public int solution(int[][] dots) {
        int y=0,x=0;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                if(dots[i][0] != dots[j][0]){
                    x = Math.abs(dots[i][0] - dots[j][0]);
                }
                if(dots[i][1] != dots[j][1]){
                    y = Math.abs(dots[i][1] - dots[j][1]);
                }
            }
        }
        
        return x*y;
    }
}