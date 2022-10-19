class Solution {
    public int[] solution(int money) {
        int[] answer = new int[]{money / 5500, money - (money / 5500 * 5500)};
        return answer;
    }
}