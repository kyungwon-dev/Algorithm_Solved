import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main{
        
    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        // 입력 및 초기화
        final int maxNum = 1000000 * 2 + 1;
        int arr[] = new int[maxNum];
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            int num = Integer.parseInt(br.readLine()) + 1000000;
            arr[num]++;
        }
        for(int i=0;i<maxNum;i++){
            if(arr[i] != 0)
                sb.append(String.valueOf(i - 1000000) + "\n");
        }
        System.out.print(sb.toString());
    }
}
