class Solution {
    public int solution(int i, int j, int k) {
        int answer = 0;
        for(int start = i;start <=j; start++){
            String str = String.valueOf(start);
            for(int strIdx = 0; strIdx < str.length();strIdx++){
                if(str.charAt(strIdx) == (char) ('0' + k))
                    answer++;
            }
   
        }
        return answer;
    }
}