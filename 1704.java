import java.util.Scanner;
import java.util.Arrays;
public class Main{
 public static void  main(String args[] ){
  int arr[]=new int[10005];
  Scanner sc=new Scanner(System.in);

  int T=sc.nextInt();

  while((T--)!=0){
   int n=sc.nextInt();
   arr[0] = 0;
   for (int i = 1; i <= n;i++)
     arr[i]=sc.nextInt();
   Arrays.sort(arr,1,n + 1);
   int ans = 0;
   for (int i = n; i >= 1; i -= 2)
    ans ^= arr[i] - arr[i-1] - 1;
   if (ans==0) System.out.printf ("Bob will win\n");
   else System.out.printf ("Georgia will win\n");
  }
 }
}