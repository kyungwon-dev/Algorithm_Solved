class Solution {
    public int solution(String[] orders) {
        int answer = 0;
        for(String order : orders){
            if(order.indexOf("americano") != -1)
                answer += 4500;
            else if(order.indexOf("cafelatte") != -1)
                answer += 5000;
            else
                answer += 4500;
        }
        return answer;
    }
}