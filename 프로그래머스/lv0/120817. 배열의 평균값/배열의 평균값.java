import java.util.stream.*;

class Solution {
    public double solution(int[] numbers) {

        return IntStream.of(numbers).sum() / (double) numbers.length;
    }
}