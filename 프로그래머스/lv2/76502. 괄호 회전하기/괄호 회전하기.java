import java.util.Stack; 

class Solution {
    public int solution(String s) {
        Stack<Integer> stack = new Stack<Integer>();
        int answer = 0;
        for(int i=0;i<s.length();i++){
            String tmp = s.substring(1,s.length());
            s = tmp + s.charAt(0);
            stack.clear();
            boolean isMake = true;
            for(int j=0;j<s.length();j++){
                if(s.charAt(j) == '(')
                    stack.push(0);
                else if(s.charAt(j) == '{')
                    stack.push(1);
                else if(s.charAt(j) == '[')
                    stack.push(2);
                else{
                    if(stack.empty()){
                        isMake = false;
                        break;
                    } 
                    int popValue = -1;
                    if(s.charAt(j) == ')')
                        popValue = 0;
                    else if(s.charAt(j) == '}')
                        popValue = 1;
                    else
                        popValue = 2;
                    if(stack.peek() == popValue){
                        stack.pop();
                    }
                    else{
                        isMake = false;
                        break;
                    }
                }
            }
            if(isMake == true && stack.size()==0){
                answer++;                
            }
        }
        
        
        return answer;
    }
}