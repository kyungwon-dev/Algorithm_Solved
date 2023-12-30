class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for(int i=0;i<queries.length;i++){
            int prev = queries[i][0];
            int next = queries[i][1];
            int tmp = arr[prev];
            arr[prev] = arr[next];
            arr[next] = tmp;
            
        }
        return arr;
    }
}