class Solution {
    public int solution(int[] array) {
        int answer = 0;
        for(int arr : array){
            String str = String.valueOf(arr);
            while(str.indexOf("7")!= -1){
                answer += 1;
                str = str.substring(str.indexOf("7")+1);
            }
        }
        return answer;
    }
}