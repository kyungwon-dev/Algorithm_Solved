class Solution {
    public int solution(String my_string, String target) {
        if(my_string.length() < target.length()) return 0;
        if(my_string.indexOf(target) == -1) return 0;
        return 1;
    }
}