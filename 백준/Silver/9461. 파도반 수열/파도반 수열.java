import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력 및 초기화
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());

        long[] triangle = new long[100];
        triangle[0] = triangle[1] = triangle[2] = 1;
        triangle[3] = triangle[4] = 2;
        for(int i=5;i<100;i++){ 
            triangle[i] = triangle[i-1] + triangle[i-5];
        }
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine(), " ");
            sb.append(triangle[Integer.parseInt(st.nextToken()) - 1 ] + "\n");
        }
        System.out.print(sb.toString());
    }
}
