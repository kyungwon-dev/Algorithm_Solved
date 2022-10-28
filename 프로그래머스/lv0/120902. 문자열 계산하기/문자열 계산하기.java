class Solution {
    public int solution(String my_string) {
        int answer = 0;
        String[] op = my_string.split(" ");
        for(int i=1;i<op.length;i+=2){
            if(i == 1){
                if(op[i].equals("+"))
                    answer = Integer.parseInt(op[i-1]) + Integer.parseInt(op[i+1]);
                else
                    answer = Integer.parseInt(op[i-1]) - Integer.parseInt(op[i+1]);
            }
            else{
                if(op[i].equals("+"))
                    answer += Integer.parseInt(op[i+1]);
                else
                    answer -= Integer.parseInt(op[i+1]);
            }
            
        }
        
        return answer;
    }
}