import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(n, new Comparator<Integer>() {
            @Override
            public int compare(Integer num1, Integer num2){
                int absNum1 = Math.abs(num1);
                int absNum2 = Math.abs(num2);
                if(absNum2 == absNum1)
                    return num1 - num2;
                return absNum1 - absNum2;
            }
        });
        for(int i=0;i<n;i++){
            int num = Integer.parseInt(br.readLine());
            if(num == 0){
                if(minHeap.peek() == null){
                    sb.append("0");
                }
                else{
                    sb.append(minHeap.poll());
                }
                sb.append("\n");
            }
            else{
                minHeap.offer(num);
            }
        }
        System.out.println(sb.toString());
    }

}
