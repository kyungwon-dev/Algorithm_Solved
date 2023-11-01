class Solution {
    public int[] solution(int[] arr, int n) {
        int i = 1;
        if(arr.length %2 == 1){
            i = 0;
        }
        for(;i<arr.length;i+=2){
            arr[i] += n;        
        }
        return arr;
    }
}