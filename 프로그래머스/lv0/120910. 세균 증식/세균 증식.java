class Solution {
    public int solution(int n, int t) {
        for(int i=0;i<t;i++) n+=n;
        return n;
    }
}