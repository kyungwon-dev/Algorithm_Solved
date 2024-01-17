class Solution {
    public int[][] solution(int[][] arr) {
        if(arr.length == arr[0].length) return arr;
        int row = arr.length;
        int col = arr[0].length;
        if(row > col) col = row;
        else row = col;
        int[][] answer = new int[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i >= arr.length)
                    answer[i][j] = 0;
                else if(j >= arr[0].length)
                    answer[i][j] = 0;
                else
                    answer[i][j] = arr[i][j];
            }
        }
        return answer;
    }
}