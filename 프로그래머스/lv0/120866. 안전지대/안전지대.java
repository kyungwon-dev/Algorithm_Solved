class Solution {
    public int solution(int[][] board) {
        int[] dy = new int[]{-1,-1,-1,0,0,1,1,1};
        int[] dx = new int[]{-1,0,1,-1,1,-1,0,1};
        
        boolean[][] check = new boolean[board.length][board.length];
        int answer = board.length * board.length;
        
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board.length;j++){
                if(board[i][j] == 1){
                    check[i][j] = true;
                    for(int d=0;d<8;d++){
                        int y = i + dy[d];
                        int x = j + dx[d];
                        if(0 <= y && y < board.length && 0 <= x && x < board.length){
                            check[y][x] = true;
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<check.length;i++){
            for(int j=0;j<check.length;j++){
                if(check[i][j]) answer--;
            }
        }
        
        return answer;
    }
}