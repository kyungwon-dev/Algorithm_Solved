import java.math.*;
import java.util.*;

class Solution {
    public int solution(int ball, int share) {
        BigInteger answer = BigInteger.ONE;
        if(share == 1) return ball;
        if(share == ball) return 1;

        share = ball - share > share? share: ball - share;
        
        for(long i=ball;i>(ball-share);i--)
            answer = answer.multiply(BigInteger.valueOf(i));
        for(long i=share;i>1;i--)
            answer = answer.divide(BigInteger.valueOf(i));
        
        return answer.intValue();
    }
}