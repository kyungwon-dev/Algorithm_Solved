class Solution {
    public int solution(String ineq, String eq, int n, int m) {
        int answer = 0;
        eq = ineq + eq;
        if (">=".equals(eq)){
            if(n >= m) return 1;
        } else if ("<=".equals(eq)){
            if(n <= m) return 1;
        } else if (">!".equals(eq)){
            if(n > m) return 1;
        } else if ("<!".equals(eq)){
            if(n < m) return 1;
        } 
        return 0;
    }
}