class Solution {
    public String solution(String rsp) {
        // 2, 0 , 5
        String answer = "";
        for(int i=0;i<rsp.length();i++){
            if(rsp.charAt(i) == '2')
                answer += "0";
            else if(rsp.charAt(i) == '0')
                answer += "5";
            else
                answer += "2";
        }
        return answer;
    }
}