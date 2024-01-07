class Solution {
    public String solution(String a, String b) {
        String answer = "";
        if(a.length() > b.length()){
            int size = b.length();
            for(int i=0;i<a.length() - size; i++){
                b = "0" + b;    
            }
        } else{
            int size = a.length();
            for(int i=0;i<b.length() - size; i++){
                a = "0" + a;    
            }
        }
        // System.out.println(a);System.out.println(b);
        int carry = 0;
        for(int i=a.length()-1; i>=0;i--){
            int aa = Integer.valueOf(a.charAt(i) - '0');
            int bb = Integer.valueOf(b.charAt(i) - '0');
            
            if(aa + bb + carry >= 10){
                answer = String.valueOf( (aa + bb + carry ) % 10) + answer;
                carry = 1;
            }
            else{
                answer = String.valueOf( (aa + bb + carry ) % 10) + answer;
                carry = 0;
            }            
        }
        if(carry == 1)
            answer = "1" + answer;
        return answer;
    }
}