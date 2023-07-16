class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        boolean[] isColored = new boolean[n+1];
        for(int s : section)
            isColored[s] = true;
        int idx = section[0];
        while(idx <= n){
            if(isColored[idx] == true){
                idx = idx + m;
                answer++;
            }
            else{
                idx = idx+1;
            }
        }
        return answer;
    }
}