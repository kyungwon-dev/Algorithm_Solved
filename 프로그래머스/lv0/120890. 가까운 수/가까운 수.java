class Solution {
    public int solution(int[] array, int n) {
        int d=500, answer = 500;
        for(int i=0;i<array.length;i++){
            int diff = Math.abs(array[i] - n);
            if(diff <= d){
                if(diff < d){
                    answer = array[i];
                }
                else
                    answer = Math.min(array[i], answer);
                d = diff;
            }
                
        }
        return answer;
    }
}