import java.math.*;

class Solution {
    public int[] solution(String[] keyinput, int[] board) {
        int[] answer = {0,0};
        int[] dy = {0,-1,0,1};
        int[] dx = {1,0,-1,0};
        for(int i=0;i<keyinput.length;i++){
            int idx= 0;
            if(keyinput[i].equals("left")){
                idx = 2;
            }
            else if(keyinput[i].equals("right")){
                idx = 0;
            }
            else if(keyinput[i].equals("up")){
                idx = 3;
            }
            else{
                idx = 1;
            }
            
            if(Math.abs(answer[0] + dx[idx]) <= (board[0]/2) && Math.abs(answer[1] + dy[idx]) <= (board[1]/2)){
                answer[0] += dx[idx];
                answer[1] += dy[idx];
            }
        }
        return answer;
    }
}