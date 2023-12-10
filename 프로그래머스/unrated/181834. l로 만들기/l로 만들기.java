class Solution {
    public String solution(String myString) {
        
        char[] myChar = myString.toCharArray();
        for(int i=0;i<myChar.length;i++){
            if(myChar[i]  < 'l'){
                myChar[i] = 'l';
            }
        }
        return String.valueOf(myChar);
    }
}