class Solution {
    public int solution(int n) {
        int num = 1;
        for(int i=1;i<11;i++){
            num *= i;
            if(n < num)
                return i-1;
        }
        return 10;
    }
}