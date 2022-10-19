class Solution {
    public int solution(int[] dot) {
        if(dot[1] < 0){
            if(dot[0] < 0) return 3;
            return 4;
        }
        else{
            if(dot[0] < 0) return 2;
            return 1;
        }
    }
}