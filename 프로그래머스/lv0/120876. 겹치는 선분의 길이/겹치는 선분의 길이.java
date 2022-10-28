import java.math.*;

class Solution {
    public int solution(int[][] lines) {
        int[] l = new int[210];
        int answer = 0;
        for(int i=0;i<lines.length;i++){
            for(int j=Math.min(lines[i][0], lines[i][1]);j<Math.max(lines[i][0], lines[i][1]);j++)
                l[j+100]++;
        }
        for(int i=0;i<210;i++){
            if(l[i]>=2)
                answer++;
        }
        
        return answer;
    }
}