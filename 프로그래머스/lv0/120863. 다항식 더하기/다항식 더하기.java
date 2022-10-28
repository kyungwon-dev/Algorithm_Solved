class Solution {
    public String solution(String polynomial) {
        String answer = "";
        int[] p = new int[2];
        String[] op = polynomial.split(" ");
        for(int i=0;i<op.length;i+=2){
            if(op[i].indexOf("x") != -1){
                op[i] = op[i].substring(0,op[i].length()-1);
                if(op[i].length() == 0)
                    op[i] = "1";
                p[0] += Integer.parseInt(op[i]);
            }
            else{
                p[1] += Integer.parseInt(op[i]);
            }
        }
        if(p[0] !=0){
            if(p[0] == 1)
                answer = "x";
            else
                answer = answer + String.valueOf(p[0]) + "x";
        }
        if(p[1] !=0){
            if(p[0] == 0)
                answer = answer + String.valueOf(p[1]);
            else
                answer = answer + " + " + String.valueOf(p[1]);
        }
        return answer;
    }
}