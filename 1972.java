//* @author:
import java.util.*;
public class Main
{
 static int max(int u,int v,int w,int x)
{
	if (u< v)u=v;
	if (u< w)u=w;
	if (u< x)u=x;
	return u;
}

 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);

   int a[][]=new int[2][7],s[]=new int[6];
       int nn=sc.nextInt();
	while ((nn--)!=0)
	{
	 int n=sc.nextInt();
        for(int i=0;i< s.length;i++)
          s[i]=sc.nextInt();
	 a[0][s[0]]=a[0][s[5]]=max(s[1],s[2],s[3],s[4]);
	 a[0][s[1]]=a[0][s[3]]=max(s[0],s[2],s[4],s[5]);
	 a[0][s[2]]=a[0][s[4]]=max(s[0],s[1],s[3],s[5]);
	 for(int i=1;i< n;i++)
	 {
	  for(int j=0;j< s.length;j++)
            s[j]=sc.nextInt();

	  a[i&1][s[0]]=a[(i+1)&1][s[5]]+max(s[1],s[2],s[3],s[4]);
	  a[i&1][s[5]]=a[(i+1)&1][s[0]]+max(s[1],s[2],s[3],s[4]);
	  a[i&1][s[1]]=a[(i+1)&1][s[3]]+max(s[0],s[2],s[4],s[5]);
	  a[i&1][s[3]]=a[(i+1)&1][s[1]]+max(s[0],s[2],s[4],s[5]);
	  a[i&1][s[2]]=a[(i+1)&1][s[4]]+max(s[0],s[1],s[3],s[5]);
	  a[i&1][s[4]]=a[(i+1)&1][s[2]]+max(s[0],s[1],s[3],s[5]);
	}
	int ans=0;
	if ((n%2)==0) for (int i=1;i<=6;i++) if (ans< a[1][i]) ans=a[1][i];
	if (n%2!=0) for (int i=1;i<=6;i++) if (ans< a[0][i]) ans=a[0][i];
	System.out.printf("%d\n",ans);
     }
  }
}


