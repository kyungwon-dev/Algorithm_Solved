import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        LinkedList<Integer> stk = new LinkedList<Integer>();
        int i=0;
        while(i< arr.length){
            if(stk.size() == 0){
                stk.add(arr[i]);
                i++;
            }
            else{
                if(stk.get(stk.size()-1) >= arr[i]){
                    stk.removeLast();
                } else{
                    stk.add(arr[i]);
                    i++;
                }
            }
        }
        return stk.stream().mapToInt(t->t).toArray();
    }
}