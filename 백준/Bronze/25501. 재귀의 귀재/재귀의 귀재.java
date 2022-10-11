import java.util.Scanner;

public class Main{

    static long isRecursionCount = 0;

    static int recursion(String s, int l, int r){
        isRecursionCount++;
        if(l >= r) 
            return 1;
        else if(s.charAt(l) != s.charAt(r)) 
            return 0;
        else
            return recursion(s, l+1, r-1);
    }

    static int isPalindrome(String s){
        return recursion(s, 0, s.length()-1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        for(int i=0;i<T;i++){
            String sentence = sc.nextLine();
            System.out.printf("%d %d\n", isPalindrome(sentence) , isRecursionCount);
            isRecursionCount = 0;
        }
        sc.close();
    }
}