import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static StringBuilder sb = new StringBuilder();
    public static int n, m;
    public static int[] nums;

    public static void recursion(int start, int cnt){
        
        if(cnt==m){
            for(int i=0;i<nums.length;i++){
                sb.append(nums[i]).append(" ");
            }
            sb.deleteCharAt(sb.length()-1);
            sb.append("\n");
            return;
        }
        for(int i=start;i<=n;i++){
            nums[cnt] = i;
            recursion(i, cnt+1);
        }
    }

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        nums = new int[m];
        recursion(1, 0);
        System.out.print(sb.toString());
    }
}
