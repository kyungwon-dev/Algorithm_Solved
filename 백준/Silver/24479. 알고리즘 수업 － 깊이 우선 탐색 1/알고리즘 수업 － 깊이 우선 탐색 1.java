import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Collections;
public class Main{

    static int[] visited;
    static int visited_idx = 1;

    static void dfs(int start, ArrayList<ArrayList<Integer>> al){
        visited[start] = visited_idx;
        visited_idx++;
        for(int a : al.get(start)){
            if(visited[a] == 0)
                dfs(a,al);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());                    
        ArrayList<ArrayList<Integer>> al = new ArrayList<>(V);
        for(int i=0;i<V;i++){
            al.add(new ArrayList<Integer>());
        }
        visited = new int[V];
        for(int i=0;i<E;i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()) - 1;
            int dest = Integer.parseInt(st.nextToken()) - 1;
            al.get(start).add(dest);
            al.get(dest).add(start);
        }
        for(int i=0;i<V;i++){
            Collections.sort(al.get(i));
        }
        dfs(R-1,al);
        for(int i=0;i<V;i++){
            System.out.println(visited[i]);
        }
    }
}