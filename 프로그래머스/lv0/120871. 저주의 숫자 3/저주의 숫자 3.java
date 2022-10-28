class Solution {
    public boolean isInThree(int num){
        String str = Integer.toString(num);
        return str.indexOf("3") >= 0 ? true : false;
    }
    
    
    public int solution(int n) {
        int answer = 0;
        int idx = 0;
        while(true){
            if( (answer % 3 == 0) || isInThree(answer)){
                answer++;
                continue;
            }
            else
                idx++;
            if(idx == n) break;
            answer++;
            
        }
        return answer;
    }
}