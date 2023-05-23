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
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(n, Collections.reverseOrder(null));
        for(int i=0;i<n;i++){
            int num = Integer.parseInt(br.readLine());
            if(num == 0){
                if(maxHeap.peek() == null){
                    sb.append("0");
                }
                else{
                    sb.append(maxHeap.poll());
                }
                sb.append("\n");
            }
            else{
                maxHeap.offer(num);
            }
        }
        System.out.println(sb.toString());

    }

}
