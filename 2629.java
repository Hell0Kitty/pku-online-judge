//* @author  mekarlos@gmail.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
            String s=""; int[] l1,l2;
        while(stdin.ready()){
            l1=new int[26];l2=new int[26];
            s=stdin.readLine().trim();
            for(int i=0;i< s.length();i++){
                l1[(int)(s.charAt(i)-'a')]++;
            }
            s=stdin.readLine().trim();
            for(int i=0;i< s.length();i++){
                l2[(int)(s.charAt(i)-'a')]++;
            }
            for(int i=0;i< 26;i++){
                l1[i]=Math.min(l1[i], l2[i]);
            }
            for(int i=0;i< 26;i++){
                for(int j=0;j< l1[i];j++){
                    System.out.print((char)(i+'a'));
                }
            }
            System.out.print("\n");
        }
    }
}

