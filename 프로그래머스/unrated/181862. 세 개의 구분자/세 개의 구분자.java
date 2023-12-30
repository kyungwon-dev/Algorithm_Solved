class Solution {
    public String[] solution(String myStr) {
        String[] answer = {};
        char[] chrMyStr = myStr.toCharArray();
        for(int i=0;i<chrMyStr.length;i++){
            if(chrMyStr[i] == 'a' || chrMyStr[i] == 'b' || chrMyStr[i] == 'c')
                chrMyStr[i] = ' ';
        }
        myStr = String.valueOf(chrMyStr);
        myStr = myStr.replaceAll("\\s+", " ").trim();
        
        answer = myStr.split(" ");
        if(answer.length == 1 && answer[0].length() == 0){
            answer = new String[1];
            answer[0] = "EMPTY";
        }
        return answer;
    }
}