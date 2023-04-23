import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int answer = 0;        

        StringTokenizer minusTokneizer = new StringTokenizer(br.readLine(), "-");
        int loop = 0;
        while(minusTokneizer.hasMoreTokens()){
            StringTokenizer plusTokenizer = new StringTokenizer(minusTokneizer.nextToken(), "+");
            while(plusTokenizer.hasMoreTokens()){
                if(loop == 0)
                    answer += Integer.parseInt(plusTokenizer.nextToken());
                else
                    answer -= Integer.parseInt(plusTokenizer.nextToken());                
            }
            loop++;
        }
        System.out.println(answer);

    }

}
