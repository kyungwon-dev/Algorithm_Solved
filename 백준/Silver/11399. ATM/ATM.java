import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collection;
import java.util.StringTokenizer;
import java.util.stream.Stream;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), "-");

        int n = Integer.parseInt(st.nextToken());

        int answer = 0;
        int[] arrs = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arrs);

        /*
         * 정렬 전 : 3 1 4 3 2
         * 정렬 후 : 1 2 3 3 4
         * 결과값 : () + 1 + (1) + 2 + (1+2) + 3 + (1+2+3) + 3 + (1+2+3+3) + 4
         */
        for(int i=0;i<n;i++)
            answer = answer + (n-i) * arrs[i];

        System.out.println(answer);
    }

}
