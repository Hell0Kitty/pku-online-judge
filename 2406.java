import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String input = "";
        while(scn.hasNext()){
            input = scn.next();
             if(input.equals(".")){
                break;
             }
            System.out.println(kmp(input));
        }
    }

    private static int kmp(String input) {
        int len = input.length();
        int[] next = new int[len + 1];

        int i = 0,j = -1;
        next[0] = -1;
        while(i < len){
            if( j == -1 || input.charAt(i) == input.charAt(j)){
                i++;
                j++;
                next[i] = j;
            }else{
                j = next[j];
            }
        }

        if(len % (len - next[len]) == 0){
            return len /(len - next[len]);
        }
        return 1;
    }
}


