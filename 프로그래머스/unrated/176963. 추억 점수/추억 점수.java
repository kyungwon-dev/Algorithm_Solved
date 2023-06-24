import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        Map<String, Integer> photoScore = new HashMap<String, Integer>();
        for(int i=0;i<name.length;i++){
            // phothScore.put(yearning[i], phothScore.getOrDefault(phothScore.get(name[i]),0));
            photoScore.put(name[i], yearning[i]);
        }
        for(int i=0;i<photo.length;i++){
            for(String p : photo[i]){
                if(photoScore.containsKey(p))
                    answer[i] += photoScore.get(p);
            }
        }
        return answer;
    }
}