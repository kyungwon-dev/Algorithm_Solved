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
        for(int i=0;i< (n%4 == 0 ? n/4 : n/4 + 1 );i++){
            sb.append("long ");
        }
        sb.append("int");
        System.out.println(sb.toString());

    }

}
