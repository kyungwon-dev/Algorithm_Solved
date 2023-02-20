import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main{
        
    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        // 입력 및 초기화
        
        // 주어지는 숫자 범위 만큼 배열을 생성하고, 주어지는 숫자를 배열 인덱스로 접근하려 함
        // 이때, 주어지는 숫자가 음수인 경우도 존재.
        // 따라서 나올 수 있는 가장 작은 값이 0이 될 수 있도록 해당 값을 더함
        // 또한, 주어진 값이 중복되지 않기 때문에 시간복잡도 내에 해결 가능
        final int adder = 1000000; // 음수 값이 나오지 않도록 보정
        final int maxNum = adder * 2 + 1; // 전체 나올 수 있는 값의 범위
        boolean arr[] = new boolean[maxNum];
        int n = Integer.parseInt(br.readLine());

        for(int i=0;i<n;i++){
            int num = Integer.parseInt(br.readLine()) + adder;
            arr[num] = true;
        }
        for(int i=0;i<maxNum;i++){
            if(arr[i]) // 어떠한 값이 나왔다면
                sb.append(String.valueOf(i - adder) + "\n");
        }
        System.out.print(sb.toString());
    }
}
