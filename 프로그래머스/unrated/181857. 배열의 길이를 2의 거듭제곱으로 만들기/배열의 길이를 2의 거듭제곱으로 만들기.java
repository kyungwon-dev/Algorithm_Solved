import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> answer = new ArrayList<Integer>();
        int i=1;
        for(;i<1024;i*=2){
            if(arr.length > i) continue;
            else if(arr.length == i) return arr;
            else break;
        }
        for(int j=0;j<arr.length;j++)
            answer.add(arr[j]);
        for(int j=arr.length;j<i;j++)
            answer.add(0);
        return answer.stream().mapToInt(k->k).toArray();
    }
}