import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.*;
public class Main{

    public static int n;
    public static int calcMin = Integer.MAX_VALUE, calcMax = Integer.MIN_VALUE; // 최소, 최대값
    public static int[] nums; // 입력받는 숫자
    public static int[] operator; // 사칙연산 중 선택할 수 있는 횟수
    public static int[] choose; // 선택한 연산자

    public static void recursion(int chooseOperarion, int order){
        if(chooseOperarion == n-1){ // 고를 수 있는 연산자를 모두 골랐을 때,
            int result = nums[0], idx = 0;
            for(int i=1;i<n;i++){
                switch(choose[idx]){
                    case 1:
                        result += nums[i];
                        break;
                    case 2:
                        result -= nums[i];
                        break;
                    case 3:
                        result *= nums[i];
                        break;
                    case 4:
                        result /= nums[i];
                        break;
                }
                idx++;
            }
            calcMax = Math.max(result, calcMax);
            calcMin = Math.min(result, calcMin);
            return;
        }

        for(int i=0;i<4;i++){
            if(operator[i] > 0){ // 해당 연산자를 고를 수 있다면
                operator[i]--; // 선택한 연산자의 개수를 감소하고
                choose[order] = i+1; // 선택한 연산자 종류를 저장.
                recursion(chooseOperarion + 1, order + 1);
                operator[i]++; // 감소시켰던 연산자의 개수를 증가하고
                choose[order] = 0; // 선택한 연산자 종류를 제거
            }
        }

    }


    public static void main(String[] args) throws IOException{        
        // 입력 및 초기화
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        n = Integer.parseInt(st.nextToken());
        nums = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        operator = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        choose = new int[n-1];
        recursion(0, 0);        
        System.out.println(calcMax + "\n" + calcMin);
    }
}
