import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
public class Main{

    static int[] visited;
    static int visited_idx = 1;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());                    
        ArrayList<ArrayList<Integer>> al = new ArrayList<>(V);
        for(int i=0;i<V;i++) al.add(new ArrayList<Integer>());        
        visited = new int[V];
        for(int i=0;i<E;i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()) - 1;
            int dest = Integer.parseInt(st.nextToken()) - 1;
            al.get(start).add(dest);
            al.get(dest).add(start);
        }
        for(int i=0;i<V;i++){
            Collections.sort(al.get(i), (Integer a, Integer b)->
            {
                int rs = 1;
                if(a >= b) rs = -1;
                return rs;
            });
        }
        R--;
        Queue<Integer> q = new LinkedList<>();
        q.add(R); visited[R] = visited_idx;
        visited_idx++;
        while(!q.isEmpty()){
            int next = q.poll();
            for(int a : al.get(next)){
                if(visited[a] == 0){
                    q.add(a);
                    visited[a] = visited_idx;
                    visited_idx++;
                }
            }
        }
        for(int i=0;i<V;i++){
            System.out.println(visited[i]);
        }
    }
}