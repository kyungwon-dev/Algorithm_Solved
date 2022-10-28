class Solution {
    public int gcd(int a, int b){
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    public int[] solution(int denum1, int num1, int denum2, int num2) {
        int ja = (num1*denum2) + (num2*denum1);
        int mo = num1 * num2 ;
        int g = gcd(mo,ja);
        return new int[]{ja / g, mo/ g};
    }
}