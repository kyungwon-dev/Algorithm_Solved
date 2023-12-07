class Solution {
    public int solution(int[] arr, int idx) {
        while(idx < arr.length){
            if(arr[idx] == 1) return idx;
            idx++;
        }
        return -1;
    }
}