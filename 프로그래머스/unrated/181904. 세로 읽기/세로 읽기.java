class Solution {
    public String solution(String my_string, int m, int c) {
        String answer = "";
        char[] my_char = my_string.toCharArray();
        for(int i=c-1;i<my_char.length;i+=m){ answer = answer + my_char[i];}
        return answer;
    }
}