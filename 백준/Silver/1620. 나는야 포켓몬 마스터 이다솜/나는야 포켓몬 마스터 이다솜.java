import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
public class Main{

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Map<String, Integer> nameEncyclopedia = new HashMap<String, Integer>();
        Map<Integer, String> indexEncyclopedia = new HashMap<Integer, String>();

        for(int i= 0;i<n; i++){
            String name = br.readLine();
            nameEncyclopedia.put(name, i+1);
            indexEncyclopedia.put(i+1, name);
        }

        for(int i=0;i<m;i++){
            String question = br.readLine();
            try{
                int idx = Integer.parseInt(question);
                sb.append(indexEncyclopedia.get(idx)).append("\n");
            }
            catch(NumberFormatException e){
                sb.append(nameEncyclopedia.get(question)).append("\n");
            }
        }
        System.out.print(sb.toString());

    }
}
