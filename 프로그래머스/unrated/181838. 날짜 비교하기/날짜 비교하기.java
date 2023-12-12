class Solution {
    public int solution(int[] date1, int[] date2) {
        for(int i=0;i<3;i++){
            if(date1[i] == date2[i])
                continue;
            else if(date1[i] > date2[i])
                return 0;
            else
                return 1;
        }
        return 0;
    }
}