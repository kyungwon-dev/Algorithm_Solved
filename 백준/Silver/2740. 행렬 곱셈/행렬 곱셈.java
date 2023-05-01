import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    
        int n, m, k;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] matrixA = new int[n][m];
        for(int i=0;i<n;i++){
            int j =0 ;
            st = new StringTokenizer(br.readLine(), " ");
            while(st.hasMoreTokens()){
                matrixA[i][j++] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine(), " ");

        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int[][] matrixB = new int[m][k];
        
        for(int i=0;i<m;i++){
            int j =0 ;
            st = new StringTokenizer(br.readLine(), " ");
            while(st.hasMoreTokens()){
                matrixB[i][j++] = Integer.parseInt(st.nextToken());
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                sb.append(matmul(i, j, m, matrixA, matrixB)).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());

    }
    public static int matmul(int indexA, int indexB, int roop, int[][] A, int[][] B) {
            int rs = 0;
            for(int i=0;i<roop;i++){
                rs = rs + (A[indexA][i] * B[i][indexB]);
            }
            
            return rs;

    }

}
