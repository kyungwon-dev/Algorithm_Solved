class Solution {
    public String solution(String my_string, int[][] queries) {
        String answer = "";
        
        for(int i=0;i<queries.length;i++){
            StringBuilder front = new StringBuilder(my_string.substring(0, queries[i][0]));
            StringBuilder mid = new StringBuilder(my_string.substring(queries[i][0], queries[i][1]+1));
            StringBuilder back = new StringBuilder(my_string.substring(queries[i][1]+1, my_string.length()));
            my_string = front.toString() + mid.reverse().toString() + back.toString();
            
        }
        return my_string;
    }
}