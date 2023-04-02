import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력 및 초기화
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        int n = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][n];
        int[][] nums = new int[n][n];

        int answer = Integer.MIN_VALUE;

        for(int i=0;i<n;i++){
            int j = 0 ;
            st = new StringTokenizer(br.readLine(), " ");
            while(st.hasMoreTokens()){
                nums[i][j++] = Integer.parseInt(st.nextToken());
            }
            if(i==0){
                dp[0][0] = nums[0][0];
                continue;
            } 
            for(j=0;j<=i;j++){
                if(j==0){
                    dp[i][j] = nums[i][j] + dp[i-1][j];
                }
                else if(j== i){
                    dp[i][j] = nums[i][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1]) + nums[i][j];
                }
                answer = Math.max(answer, dp[i][j]);
            }
        }
        answer = Math.max(answer, dp[0][0]);
        System.out.println(answer);
    }
}
