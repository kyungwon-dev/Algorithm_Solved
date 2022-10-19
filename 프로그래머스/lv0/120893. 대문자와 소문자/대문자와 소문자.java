class Solution {
    public String solution(String my_string) {
        String answer = "";
        char[] chars = my_string.toCharArray();
        for(int i=0;i<chars.length;i++){
            if(chars[i] < 'a')
                chars[i] = Character.toLowerCase(chars[i]);
            else 
                chars[i] = Character.toUpperCase(chars[i]);
        }
        return String.valueOf(chars);
    }
}

