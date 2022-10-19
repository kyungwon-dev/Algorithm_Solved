class Solution {
    public String[] solution(String my_str, int n) {
        String[] answer = new String[my_str.length()/n + (my_str.length()%n == 0? 0 : 1)];
        for(int i=0;i<my_str.length();i+=n)
            if(i+n < my_str.length())
                answer[i/n] = my_str.substring(i,i+n); 
            else
                answer[i/n] = my_str.substring(i); 
        return answer;
    }
}