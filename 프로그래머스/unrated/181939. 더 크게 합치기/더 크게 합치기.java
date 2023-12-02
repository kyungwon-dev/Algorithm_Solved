class Solution {
    public int solution(int a, int b) {
        String a_b = String.valueOf(a) + String.valueOf(b);
        String b_a = String.valueOf(b) + String.valueOf(a);
        if(Integer.valueOf(a_b) > Integer.valueOf(b_a)){
            return Integer.valueOf(a_b);
        }
            
        return Integer.valueOf(b_a);
    }
}