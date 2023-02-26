/* 2023.02.20 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
public class Main{

    /*
     * Hoars pivot을 이용한 Quick Sort
     * https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
     */
    public static int partition(List<Integer> list, int left, int right){
        int pivotValue = list.get(left);
        
        int i = left - 1, j = right + 1;
        while(true){

            do{
                i++;   
            }while(list.get(i) < pivotValue);

            do{
                j--;
            }while(list.get(j) > pivotValue);

            if(i >= j){
                return j;
            }

            int tmp = list.get(i);
            list.set(i, list.get(j));
            list.set(j, tmp);
        }
    }

    public static void quickSort(List<Integer> list, int left, int right){
        if(left < right){
            int pivot = partition(list, left, right);
            quickSort(list, left, pivot);
            quickSort(list, pivot + 1, right);
        }

    }


    public static void main(String[] args) throws IOException{        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        // 입력 및 초기화

        List<Integer> numList = new ArrayList<Integer>(); // 입력받은 숫자
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>(); // 입력받은 숫자(key) 대한 압축된 좌표값 보여줌(value)
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken()); 

        st = new StringTokenizer(br.readLine(), " ");
        for(int i=0;i<n;i++){
            int num = Integer.parseInt(st.nextToken());
            numList.add(num); // 입력받은 숫자 저장
            if(!map.containsKey(num))
                map.put(num, 0); // 입력받은 숫자 중 중복을 제외한 값들을 저장
        }
        
        List<Integer> keyList = new ArrayList<Integer>(map.keySet());
        quickSort(keyList, 0, keyList.size()-1); // hoares Quick Sort
        
        int coordinateCompress = 0;
        for(Integer key : keyList){
            map.put(key, coordinateCompress++); // keyList 배열은 정렬되어 있음. 해당 배열로부터 나오는 순서대로 value값 저장
        }
        for(Integer num : numList){
            sb.append(Integer.toString(map.get(num)));
            sb.append(" ");
        }
        System.out.println(sb);
    }
}
