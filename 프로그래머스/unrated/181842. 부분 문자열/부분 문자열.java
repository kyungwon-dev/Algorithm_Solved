class Solution {
    public int solution(String str1, String str2) {
        if(str1.length() > str2.length() || str2.indexOf(str1) == -1) return 0;
        return 1;
    }
}