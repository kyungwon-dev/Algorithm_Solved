class Solution {
    public int solution(String A, String B) {
        for(int i=0;i<A.length();i++){
            String tmp = A.substring(A.length()-i) + A.substring(0,A.length()-i);
            if(tmp.equals(B)) return i;
        }
        return -1;
    }
}