class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        int a_b = Integer.valueOf(String.valueOf(a) + String.valueOf(b));
        int mul_a_b = 2*a*b;
        if(a_b < mul_a_b) return mul_a_b;
        return a_b;
    }
}