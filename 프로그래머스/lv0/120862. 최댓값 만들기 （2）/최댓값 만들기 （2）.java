import java.util.stream.*;

class Solution {
    public int solution(int[] numbers) {
        int answer = -100000001;
        for(int i=0;i<numbers.length-1;i++){
            for(int j=i+1;j<numbers.length;j++)
                answer = Math.max(numbers[i] * numbers[j], answer);
        }
        return answer;
    }
}