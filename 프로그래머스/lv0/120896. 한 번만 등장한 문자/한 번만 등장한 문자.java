class Solution {
    public String solution(String s) {
        String answer = "";
        int[] counterCharacter = new int[26];
        for(int i=0;i<s.length();i++){
            counterCharacter[s.charAt(i) - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(counterCharacter[i] == 1)
                answer += String.valueOf( (char) ('a' + i));
        }
        return answer;
    }
}