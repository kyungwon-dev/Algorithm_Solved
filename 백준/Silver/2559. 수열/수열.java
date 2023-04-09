import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        // 사용할 변수
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] nums = new int[n+1];
        int idx = 1; 
        int answer = Integer.MIN_VALUE;

        st = new StringTokenizer(br.readLine(), " ");

        while(st.hasMoreTokens()){
            nums[idx] = nums[idx - 1] + Integer.parseInt(st.nextToken());
            idx++;
        }
        for(int i=k;i<=n;i++){
            answer = Math.max(answer, nums[i] - nums[i - k]);
        }
        System.out.println(answer);
    }

}
