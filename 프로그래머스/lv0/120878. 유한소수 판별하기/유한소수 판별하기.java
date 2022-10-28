class Solution {
    
    public int gcd(int a, int b){
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    
    public int solution(int a, int b) {
        int g = gcd(a,b);
        a /=g;
        b /=g;
        
        // 소인수분해
        while(b!=1){
            if(b%2 == 0)
                b/=2;
            else if(b%5 == 0)
                b /=5;
            else
                return 2;
        }
        return 1;
    }
}