class Solution {
    public int solution(int[] arr) {
        int answer = -1;
        int sameCount = 0;
        while(sameCount != arr.length){
            sameCount = 0;
            int[] prev = new int[arr.length];
            for(int i =0;i<prev.length;i++){
                prev[i] = arr[i];
            }
            for(int i=0;i<arr.length;i++){
                if(arr[i] >= 50 && arr[i]%2 == 0){
                    arr[i] = arr[i] / 2;
                } else if(arr[i] < 50 && arr[i] %2 == 1){
                    arr[i] = arr[i] * 2 + 1;
                }
                if(arr[i] == prev[i])
                    sameCount++;
            }
            answer++;
        }
        return answer;
    }
}