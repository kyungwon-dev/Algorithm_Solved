class Solution {
    public int solution(String[] board) {
        // game 규칙이 어긋나는지 확인
        // 1. O,X 개수를 통한 체크
        int oCnt =0, xCnt = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i].charAt(j) == 'O')
                    oCnt++;
                else if(board[i].charAt(j) == 'X')
                    xCnt++;
            }
        }
        // 선공과 후공의 개수 차이는 2 이상이거나 음수일 수 없음.
        if( ((oCnt - xCnt) > 1) || ((oCnt - xCnt) < 0) )
            return 0;
        
        // 2. 선공 또는 후공이 이미 1줄을 완성했으나 계속 게임을 진행한 경우.
        // O, X 둘 다 이기면 안됨
        // O가 이겼다면, X의 개수는 O의 개수-1 이어야만 함
        // X가 이겻다면, O의 개수는 X의 개수와 동일해야 함.
        int ssy[] = new int[]{1,-1, 0, 0,-1, 1,-1, 1, 1, 2, 0, 0,-1,-2, 0, 0};
        int ssx[] = new int[]{0, 0,-1, 1,-1, 1, 1,-1, 0, 0, 1, 2, 0, 0,-1,-2};
        int sy[] = new int[]{1,0,2};
        int sx[] = new int[]{1,0,2};
        
        boolean oWin = false, xWin = false;
        for(int i=0;i<8;i+=2){
            int dy = sy[0] + ssy[i], ddy = sy[0] + ssy[i+1];
            int dx = sx[0] + ssx[i], ddx = sx[0] + ssx[i+1];
            if(board[dy].charAt(dx) == 'O' && board[sy[0]].charAt(sx[0]) == 'O' && board[ddy].charAt(ddx) == 'O'){
                
                oWin = true; 
            }
            if(board[dy].charAt(dx) == 'X' && board[sy[0]].charAt(sx[0]) == 'X' && board[ddy].charAt(ddx) == 'X'){
                xWin = true; 
            }    
        }
        
        for(int i=8;i<12;i+=2){
            int dy = sy[1] + ssy[i], ddy = sy[1] + ssy[i+1];
            int dx = sx[1] + ssx[i], ddx = sx[1] + ssx[i+1];
            if(board[dy].charAt(dx) == 'O' && board[sy[1]].charAt(sx[1]) == 'O' && board[ddy].charAt(ddx) == 'O'){
                oWin = true; 
            }
            if(board[dy].charAt(dx) == 'X' && board[sy[1]].charAt(sx[1]) == 'X' && board[ddy].charAt(ddx) == 'X'){
                xWin = true; 
            }    
        }
        
        for(int i=12;i<16;i+=2){
            int dy = sy[2] + ssy[i], ddy = sy[2] + ssy[i+1];
            int dx = sx[2] + ssx[i], ddx = sx[2] + ssx[i+1];
            if(board[dy].charAt(dx) == 'O' && board[sy[2]].charAt(sx[2]) == 'O' && board[ddy].charAt(ddx) == 'O'){
                oWin = true; 
            }
            if(board[dy].charAt(dx) == 'X' && board[sy[2]].charAt(sx[2]) == 'X' && board[ddy].charAt(ddx) == 'X'){
                xWin = true; 
            }    
        }
        
        if(oWin && xWin) return 0;
        if(oWin && ( (oCnt - xCnt) != 1)) return 0;
        if(xWin && ( (oCnt - xCnt) != 0)) return 0;
        return 1;
    }
}