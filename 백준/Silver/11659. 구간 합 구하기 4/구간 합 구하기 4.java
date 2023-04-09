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
        int[] nums = new int[n+1];
        int idx = 1; 

        // 누적합 생성
        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()){
            nums[idx] = nums[idx-1] + Integer.parseInt(st.nextToken());
            idx++;
        }

        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine(), " ");
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            sb.append(nums[end] - nums[start-1]).append("\n");
        }
        System.out.println(sb.toString());

    }

}
