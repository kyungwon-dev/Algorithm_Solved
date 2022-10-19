class Solution {
    public int solution(int order) {
        int answer = 0;
        String num_string = String.valueOf(order);
        for(int i=0;i<num_string.length();i++){
            int num = Character.getNumericValue(num_string.charAt(i));
            if(num % 3 == 0 && num >=3)
                answer++;
            
        }
        return answer;
    }
}