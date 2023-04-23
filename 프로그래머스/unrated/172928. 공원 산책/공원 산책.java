import java.util.StringTokenizer;

class Solution {
    int sy = 0, sx = 0; // 로봇강아지 위치를 담아줄 좌표
    
    public void searchRobotDog(String[] park){
        // 로봇 강아지 위치 찾기
        for(int i=0;i<park.length;i++){
            for(int j=0;j<park[i].length();j++){
                if(park[i].charAt(j)== 'S'){
                    sy = i;
                    sx = j;
                    return;
                }
            }
        }
    }
    
    public int[] solution(String[] park, String[] routes) {
        searchRobotDog(park);
        for(int i=0;i<routes.length;i++){
            StringTokenizer st = new StringTokenizer(routes[i], " ");
            int dy=0, dx=0;
            switch(st.nextToken().charAt(0)){
                case 'E':
                    dy = 0;
                    dx = 1;
                    break;
                case 'S':
                    dy = 1;
                    dx = 0;
                    break;
                case 'W':
                    dy = 0;
                    dx = -1;
                    break;
                case 'N':
                    dy = -1;
                    dx = 0;
                    break;
            }
            int moves = Integer.parseInt(st.nextToken());
            int ty = sy, tx = sx;
            boolean isMove = true;
            for(int d=0;d<moves;d++){
                if(ty + dy < 0 || ty + dy >= park.length 
                   || tx + dx < 0 || tx + dx >= park[0].length() ){
                    isMove = false;
                    break;
                }
                    
                if(park[ty+dy].charAt(tx + dx) == 'X'){
                    isMove = false;
                    break;
                }
                ty = ty + dy;
                tx = tx + dx;
            }
            if(isMove){
                sy = ty;
                sx = tx;
            }
        }
        return new int[]{sy, sx};
    }
}