import java.util.*;

class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        int answer = 0;
        int score = 10000;
        SortedMap<Integer, Boolean> rankMap = new TreeMap<Integer, Boolean>();
        SortedMap<Integer, Integer> indexMap = new TreeMap<Integer, Integer>();
        
        for(int i=0;i<rank.length;i++){
            rankMap.put(rank[i], attendance[i]);
            indexMap.put(rank[i], i);
        }
        
        for(int i=1;i<=rank.length;i++){
            if(rankMap.get(i)){
                answer = answer + (score * indexMap.get(i));
                score /=100;
            }
            if(score == 0) break;
        }
        
        
        return answer;
    }
}