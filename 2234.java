import java.util.Scanner;


public class Main {

public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   while(true) {
   int n = cin.nextInt();
   int i = 0;
   int[] a = new int[n];
   while(n > 0) {
    a[i++] = cin.nextInt();
    n--;
   }
    for(i=1 ; i< a.length; i++)
     a[i]=a[i]^a[i-1];
    if(a[a.length-1] != 0)
     System.out.println("Yes");
    else
     System.out.println("No");
   }

}

}


