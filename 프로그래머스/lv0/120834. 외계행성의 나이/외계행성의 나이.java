class Solution {
    public String solution(int age) {
        String str_age = String.valueOf(age);
        String answer = "";
        for(char c : str_age.toCharArray()){
            answer += String.valueOf((char) ( c - '0' + 'a') );
        }
        
        return answer;
    }
}