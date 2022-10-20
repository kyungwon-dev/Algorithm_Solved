class Solution {
    public int solution(int[] numbers, int k) {
        int answer = 0;
        int idx = 0;
        while(k>0){
            answer = numbers[idx];
            idx = (idx+2) % numbers.length;
            k--;
        }
        
        return answer;
    }
}