import java.util.*;

class Solution {
    public int[] solution(int n) {
        List<Integer> arr = new ArrayList<Integer>();
        do{
            arr.add(n);
            if(n%2 == 0){
                n /=2;
            }
            else{
                n = n*3 + 1;
            }
        }while(n!=1);
        arr.add(1);
        return arr.stream().mapToInt(i->i).toArray();
    }
}