import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer minusTokneizer = new StringTokenizer(br.readLine(), "-");

        int loop = 0;
        int answer = 0;        
        
        /*
         * 주어지는 문자열의 형태
         * - 30+20-10+30......-10+20..
         * 따라서, '-'를 기준으로 자르고, '+'로 이어진 수식에 대해 수행.
         * 모든 '+' 기호에 대해 진행 후, '-' 를 수행하면 가장 작은 값을 구할 수 있다.
         */
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
