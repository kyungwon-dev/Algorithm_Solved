import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    static int n, cnt;

    public static int recursion(String str, int left, int right){
        cnt++;
        if(left >= right) return 1;
        else if(str.charAt(left) != str.charAt(right)) return 0;
        else return recursion(str, left + 1, right - 1);
    }

    public static int isPalindrome(String str){
        return recursion(str, 0, str.length() - 1);
    }

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        StringBuilder sb;

        // 입력 및 초기화
        n = Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++){
            sb = new StringBuilder(br.readLine());
            // System.out.println();
            cnt = 0;
            System.out.println(isPalindrome(sb.toString()) + " " + cnt);
        }
    }

}
