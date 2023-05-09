import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        int n, m;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int left = 0, right = Integer.MIN_VALUE;
        long sum = 0;
        st = new StringTokenizer(br.readLine(), " ");
        List<Integer> arr = new ArrayList<>();
        while(st.hasMoreTokens()){
            int tree = Integer.parseInt(st.nextToken());
            arr.add(tree);
            if(right <= tree) right = tree;
        }
        int mid = 0;
        right++;
        while(left <= right){
            mid = (left + right) /2;
            sum = 0;
            for(Integer t : arr){
                sum += (t-mid > 0 ? t - mid : 0);
            }
            if(sum >= m){
                left = mid +1;
            }
            else{
                right = mid - 1;
            }
        }
        System.out.println( (left + right) /2);

    }

}
