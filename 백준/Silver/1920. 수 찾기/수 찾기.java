import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        // n과 n개의 자연수
        int n = Integer.parseInt(st.nextToken());
        Map<String, String> map = new HashMap<String, String>();
        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()){
            map.put(st.nextToken(), "1");
        }
        
        // m과 m개의 자연수
        st = new StringTokenizer(br.readLine(), " ");
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<m;i++){
            String str = st.nextToken();
            if(map.containsKey(str)){
                sb.append(map.get(str)).append("\n");
            }
            else{
                sb.append("0").append("\n");
            }
        }
        System.out.println(sb.toString());

    }

}
