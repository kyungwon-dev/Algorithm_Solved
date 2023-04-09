import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        StringBuilder sb = new StringBuilder();

        // 사용할 변수
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] cumulativeSum = new int[n+1][n+1];
        // 누적합 생성
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine(), " ");
            int idx = 1;
            while(st.hasMoreTokens()){
                cumulativeSum[i][idx] = cumulativeSum[i][idx-1] + cumulativeSum[i-1][idx] - cumulativeSum[i-1][idx-1] + Integer.parseInt(st.nextToken());
                idx++;
            }
        }
        
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine(), " ");
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            sb.append(cumulativeSum[x2][y2] - cumulativeSum[x1-1][y2] - cumulativeSum[x2][y1-1] + cumulativeSum[x1-1][y1-1]).append("\n");
        }
        System.out.println(sb.toString());

    }

}
