class Solution {
    public String solution(String myString, String pat) {
        String answer = "";
        while(myString.indexOf(pat) != -1){
            answer += myString.substring(0, myString.indexOf(pat) + pat.length());
            myString = myString.substring(myString.indexOf(pat) + pat.length());
            
        }
        return answer;
    }
}