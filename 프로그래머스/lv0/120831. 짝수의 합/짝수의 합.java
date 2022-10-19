import java.util.stream.*;

class Solution {
    
    public int solution(int n) {
        return IntStream.range(0,n+1).filter(i-> i%2 == 0).sum();
    }
}