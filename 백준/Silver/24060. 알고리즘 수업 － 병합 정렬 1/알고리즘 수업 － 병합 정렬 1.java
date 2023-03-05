import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
public class Main{

    static int K, n;
    static int[] arr, tmp;
    public static void mergeSort(int left, int right){
        if(K==0) return;
        if(left < right){
            int mid = (left + right)  / 2;
            mergeSort(left, mid);
            mergeSort(mid+1, right);
            merge(left, mid, right);
        }
    } 

    public static void merge(int left, int mid , int right){
        int i = left, j = mid+1, k = 0;
        
        if(K==0) return;
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                tmp[k++] = arr[i++];
            }
            else{
                tmp[k++] = arr[j++];
            }
        }
        while(i<=mid)
            tmp[k++] = arr[i++];
        while(j<=right)
            tmp[k++] = arr[j++];        
        i = left; 
        k = 0;
        while(i<=right){
            arr[i++] = tmp[k++];
            K--;
            if(K==0){
                System.out.println(arr[i-1]);
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 입력 및 초기화
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        n = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = Arrays.stream(br.readLine().split(" "))
                        .mapToInt(Integer::parseInt).toArray();
        tmp = new int[arr.length];
        mergeSort(0, n-1);
        if(K>0)
            System.out.println(-1);
    }

}
