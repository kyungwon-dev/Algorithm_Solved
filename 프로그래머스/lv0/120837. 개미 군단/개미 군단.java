class Solution {
    public int solution(int hp) {
        int[] ant = new int[]{5,3,1};
        int answer = 0;
        for(int i=0;i<ant.length;i++){
            answer += hp/ant[i];
            hp = hp % ant[i];
        }
        
        return answer;
    }
}