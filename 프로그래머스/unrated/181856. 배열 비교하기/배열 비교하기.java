import java.util.*;

class Solution {
    public int solution(int[] arr1, int[] arr2) {
        if(arr1.length == arr2.length){
            int arr1_sum = Arrays.stream(arr1).sum();
            int arr2_sum = Arrays.stream(arr2).sum();
            if(arr1_sum == arr2_sum) return 0;
            else if(arr1_sum > arr2_sum) return 1;
            else return -1;
        } else if(arr1.length > arr2.length) return 1;
        return -1;
    }
}