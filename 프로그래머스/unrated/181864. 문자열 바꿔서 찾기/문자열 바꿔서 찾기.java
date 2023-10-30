class Solution {
    public int solution(String myString, String pat) {
        String rev = "";
        for(int i=0;i<myString.length();i++){
            if(myString.charAt(i) == 'A'){
                rev += "B";
            }
            else{
                rev += "A";
            }
        }
        System.out.println(rev);
        if(rev.indexOf(pat) == -1) return 0;
        return 1;
    }
}