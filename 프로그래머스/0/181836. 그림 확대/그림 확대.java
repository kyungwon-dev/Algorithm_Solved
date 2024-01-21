class Solution {
    public String[] solution(String[] picture, int k) {
        String[] answer = new String[picture.length * k];
        for(int i=0;i<answer.length;i++){
            StringBuilder sb = new StringBuilder();
            for(int j=0;j<picture[i/k].length(); j++){
                for(int l=0;l<k;l++){
                    sb.append(picture[i/k].charAt(j));
                }

            }
            answer[i] = sb.toString();
        }

        return answer;
    }
}