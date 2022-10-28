class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        for(int i=0;i<quiz.length;i++){
            String[] cmd = quiz[i].split(" ");
            int calc = 0;
            if(cmd[1].equals("-")){
                calc = Integer.parseInt(cmd[0]) - Integer.parseInt(cmd[2]);
            }
            else{
                calc = Integer.parseInt(cmd[0]) + Integer.parseInt(cmd[2]);
            }
            if(String.valueOf(calc).equals(cmd[4])){
                answer[i] = "O";
            }
            else
                answer[i] = "X";
        }
        return answer;
    }
}