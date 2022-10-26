import java.util.*;

class Solution {
    
    class Morse implements Comparator<Morse>{
        String alpha;
        String morse;
        Morse(){
            
        }
        Morse(String alpha, String morse){
            this.alpha = alpha;
            this.morse = morse;
        }
        public int compare(Morse a, Morse b){
            
            return b.morse.length() - a.morse.length();
            
        }
    }
    
    public String solution(String letter) {
        String answer = "";
        List<Morse> morses = new ArrayList<Morse>();
        String[] ms = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<ms.length;i++){
            morses.add(new Morse(String.valueOf( (char) ('a'+i) ), ms[i]));
            
        }        
        Collections.sort(morses, new Morse());
        for(int i=0;i<ms.length;i++){
            letter = letter.replace(morses.get(i).morse, morses.get(i).alpha);
        }
        
        letter = letter.replace(" ","");
        
        return letter;
    }
}