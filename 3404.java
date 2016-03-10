//* @author: ccQ.SuperSupper
import java.util.*;
import java.math.*;

public class Main {

 public static void main(String[] args) {

    int i,n,ans;
    int way[] = new int[60];
    Scanner cin = new Scanner(System.in);

    while(cin.hasNext())
    {
        n = cin.nextInt();
        for(i=0;i< n;++i)
            way[i] = cin.nextInt();
        Arrays.sort(way,0,n);
        ans = search(n,way);
        System.out.println(ans);
    }
   }

  public static int search(int n,int way[])
  {
    int  ans=0,i,j;
    if(n==1) return way[0];
    if(n==2) return way[1];
    if(n==3) return min(way[2]+way[0]+way[1],way[2]+way[1]+way[1]);
    return search(n-2,way)+min(way[n-1]+way[0]+way[1]+way[1],way[n-1]+way[n-2]+way[0]+way[0]);
   }
    public static int min(int a,int b)
    {
        if(a>b) return b;
        return a;
    }

}

