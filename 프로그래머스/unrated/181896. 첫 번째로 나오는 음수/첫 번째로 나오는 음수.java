class Solution {
    public int solution(int[] num_list) {
        int i=0;
        for(int num : num_list){
            if(num < 0)
                return i;
            i++;
        }
        return -1;
    }
}