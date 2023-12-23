import java.util.*;

class Solution {
    public int[] solution(int[] arr, boolean[] flag) {
        int[] answer = {};
        List<Integer> arrX = new ArrayList<Integer>();
        for(int i=0;i<arr.length;i++){
            if(flag[i]){
                for(int j=0;j<arr[i]*2;j++){
                    arrX.add(arr[i]);    
                }
            } else{
                for(int j=0;j<arr[i];j++){
                    arrX.remove(arrX.size()-1);
                }
            }
        }
        return arrX.stream().mapToInt(i->i).toArray();
    }
}