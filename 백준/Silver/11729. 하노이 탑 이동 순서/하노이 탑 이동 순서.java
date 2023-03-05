import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    static StringBuilder sb = new StringBuilder();

    public static void recursion(int n, int from, int assist, int end){
        if(n == 1){
            sb.append(from + " " + end + "\n");
        }
        else{
            recursion(n-1, from, end, assist); // from 위치에서 end를 거쳐 assist로 이동
            sb.append(from + " " + end + "\n");
            recursion(n-1, assist, from, end); // assist위치에서 from을 거쳐 end로 이동
        }
        
    }

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
 
        // 입력 및 초기화
        int n = Integer.parseInt(st.nextToken());
        sb.append((int)Math.pow(2, n) -1 + "\n");
        recursion(n, 1, 2, 3); // from 위치에서 assist를 거쳐 end로 이동
        System.out.println(sb.toString());
    }
}
