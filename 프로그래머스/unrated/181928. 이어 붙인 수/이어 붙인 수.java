class Solution {
    public int solution(int[] num_list) {
        String even = "", odd = "";
        for(int num: num_list){
            if(num%2 == 0)
                even += (char)('0' + num);
            else
                odd += (char)('0' + num);
        }
        
        return Integer.parseInt(even) +  Integer.parseInt(odd);
    }
}