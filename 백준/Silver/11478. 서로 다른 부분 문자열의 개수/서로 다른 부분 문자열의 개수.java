import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashSet;
public class Main{

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        Set<String> substr = new HashSet<String>();
        String str = st.nextToken();
        for(int i=0;i<str.length();i++){
            for(int j=0;j<str.length()-i;j++){
                substr.add(str.substring(j, j+i+1));
            }
        }
        System.out.println(substr.size());

    }
}
