import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb = new StringBuilder();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder(null));

        int n = Integer.parseInt(st.nextToken());

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            if(num == 0){
                if(maxHeap.peek() == null){
                    sb.append("0");
                }
                else{
                    sb.append(maxHeap.poll().toString());
                }
                sb.append("\n");
            }
            else{
                maxHeap.add(num);
            }
        }
        System.out.println(sb.toString());

    }

}
