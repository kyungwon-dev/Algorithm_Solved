/* 2023.02.20 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{
        
    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        // 입력 및 초기화
        
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken()); // 응시자의 수 1 ~ 1000
        int k = Integer.parseInt(st.nextToken()); // 상을 받는 사람의 수 1 ~ n
        int[] studentScores = new int[10001]; // 학생의 점수 범위. 0 ~ 10000
        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens())
            studentScores[Integer.parseInt(st.nextToken())]++; // 점수에 해당하는 학생 누적
        for(int i=10000; i>=0; i--){
            k -= studentScores[i];
            if(k <=0){ // 상을 받는 사람의 등수보다 더 많은 사람이 나온 경우
                System.out.println(i);
                break;
            }
        }
        
    }
}
