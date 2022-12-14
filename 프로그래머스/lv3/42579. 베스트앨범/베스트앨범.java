import java.util.*;

class Solution {
    class Music implements Comparable<Music>{
        int idx;
        int time;
        public Music(int idx, int time){
            this.idx = idx;
            this.time = time;
        }
        
        @Override
        public int compareTo(Music m){
            if(this.time == m.time)
                return Integer.compare(this.idx, m.idx);
            return -Integer.compare(this.time, m.time);
        }
        
        @Override
        public String toString(){
            return this.idx + " " + this.time;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> songs = new HashMap<>();
        HashMap<String, List<Music>> musics = new HashMap<>();
        
        for(int i=0;i<genres.length;i++){
            if(songs.get(genres[i]) == null){
                musics.put(genres[i], new ArrayList<Music>());   
            }
            songs.put(genres[i],songs.getOrDefault(genres[i],0)+plays[i]);
            musics.get(genres[i]).add(new Music(i, plays[i]));
        }
        //
        List<String> list = new ArrayList<>(songs.keySet());
        list.sort(new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return -Integer.compare(songs.get(o1),songs.get(o2));
            }
        });
        List<Integer> answer = new ArrayList<>();
        
        for(String s:list){
            Collections.sort(musics.get(s));
            int cnt = 0;
            for(Music m : musics.get(s)){
                answer.add(m.idx);
                cnt++;
                if(cnt == 2) break;
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
