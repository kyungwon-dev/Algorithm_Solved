import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;
public class Main{

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        int n = Integer.parseInt(st.nextToken()); // A집합의 원소의 개수
        int m = Integer.parseInt(st.nextToken()); // B집합의 원소의 개수

        int cnt = 0;
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        st = new StringTokenizer(br.readLine()," ");
        while(st.hasMoreElements()){
            map.put(Integer.parseInt(st.nextToken()), 1);
        }
        st = new StringTokenizer(br.readLine()," ");
        
        while(st.hasMoreElements()){
            int tmp = Integer.parseInt(st.nextToken());
            if(map.containsKey(tmp))
                map.put(tmp, 0);
            else
                map.put(tmp, 1);
        }

        for(Map.Entry<Integer, Integer> tmp: map.entrySet()){
            if(tmp.getValue() != 0)
                cnt++;
        }
        System.out.println(cnt);
   
    }
}
