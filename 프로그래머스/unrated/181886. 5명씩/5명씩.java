class Solution {
    public String[] solution(String[] names) {
        int size = names.length/5 + (names.length%5 == 0 ? 0 : 1);
        String[] answer = new String[size];
        for(int i=0;i<names.length;i+=5){
            answer[i/5] = names[i];
        }
        return answer;
    }
}