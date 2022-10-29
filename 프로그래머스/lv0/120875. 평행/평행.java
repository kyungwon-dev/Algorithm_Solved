class Solution {
    
    int answer = 0;
    
    public int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    
    
    public void go(int[][]dots, int k, boolean[] check){
        if(answer == 1) return;
        if(k==2){
            int dx1=0, dy1=0, dx2=0, dy2=0;
            for(int i=0;i<4;i++){
                if(check[i] == true){
                    if(dx1==0 && dy1==0){
                        dx1 = dots[i][0];
                        dy1 = dots[i][1];
                    }
                    else{
                        dx1 = dx1-dots[i][0];
                        dy1 = dy1-dots[i][1];
                    }
                }
                else{
                    if(dx2==0 && dy2==0){
                        dx2 = dots[i][0];
                        dy2 = dots[i][1];
                    }
                   else{
                        dx2 = dx2-dots[i][0];
                        dy2 = dy2-dots[i][1];
                    }
                }
            }
            int d1 = gcd(dx1,dy1), d2 = gcd(dx2,dy2);
            dx1 /=d1;dy1/=d1;dx2 /=d2;dy2/=d2;
            if(dx1 == dx2 && dy1 == dy2)
                answer++;
            
        }
        for(int i=0;i<4;i++){
            if(check[i] == true)
                continue;
            check[i] = true;
            go(dots, k+1, check);
            check[i] = false;
        }
        
    }
    
    public int solution(int[][] dots) {
        
        go(dots, 0, new boolean[4]);
        return answer;
    }
}