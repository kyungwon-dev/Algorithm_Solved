import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.Stream;
public class Main{

    static int[][] colorPaper;
    static int [] countPapers = new int[2];

    public static void main(String[] args) throws IOException{        
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        int n = Integer.parseInt(st.nextToken());

        colorPaper = new int[n][n];
        
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine(), " ");
            int j=0;
            while(st.hasMoreTokens()){
                colorPaper[i][j++] = Integer.parseInt(st.nextToken());
            }
        }
        calcPapers(0, 0, 0, n, n);
        System.out.println(countPapers[0]);
        System.out.println(countPapers[1]);
    }

    public static void calcPapers(int pos, int sx, int sy, int dx, int dy){
        boolean isBlue = false;
        boolean isWhite = false;
        for(int i=sy;i<dy;i++){
            for(int j=sx;j<dx;j++){
                if(colorPaper[i][j] == 0) isWhite = true;
                else isBlue = true;
                if(isWhite && isBlue) break;
            }
        }

        if(isWhite && isBlue){
            calcPapers(1, (sx + dx)/2 , sy, dx, (sy + dy)/2); // 1사분면
            calcPapers(2, (sx + dx)/2, (sy + dy)/2, dx, dy); // 2사분면
            calcPapers(3, sx, (sy + dy)/2 , (sx + dx)/2, dy); // 3사분면
            calcPapers(4, sx, sy, (sx + dx)/2, (sy + dy)/2); // 4사분면
        }
        else{
            if(isWhite){
                countPapers[0]++;
            }
            else{
                countPapers[1]++;
            }
        }
    }

}
