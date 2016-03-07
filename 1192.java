import java.util.Scanner;
public class Main {
  static int n;

  static int x[];
  static int y[];
  static int c[];
  //int dp[1000];
  static int ans=0;

static int search(int i,int parent)
{
    int ret=0,t;
    for(int j=0;j<n;j++)
    {
        if(parent!=j&&Math.abs(x[i]-x[j])+Math.abs(y[i]-y[j])==1)
        {
            t=search(j,i);
            if(t>0)ret+=t;
        }
    }
    if(ret+c[i]>ans)ans=ret+c[i];
    return ret+c[i];
}

public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
   n=sc.nextInt();
   x=new int[n];
   y=new int[n];
   c=new int[n];
    for(int i=0;i<n;i++){
      x[i]=sc.nextInt();
      y[i]=sc.nextInt();
      c[i]=sc.nextInt();
    }
       
    search(0,-1);
    System.out.println(ans);
   }
}
