import java.util.*;
public class Main {

 static StringBuffer res = new StringBuffer();
 public static void main(String[] args){
  Scanner in = new Scanner(System.in);
  int maxn=1100000;
  int a[]=new int[11];
  boolean f[]=new boolean[maxn];
  int n;
  a[0]=1;
  for(int i=1;i<=10;i++) a[i]=i*a[i-1];
  Arrays.fill(f,false);
  f[0]=true;
  for(int i=0;i<11;i++)
   for(int j=maxn;j>=a[i];j--)
	if(f[j-a[i]]) f[j]=true;
  while(in.hasNext()){
     n=in.nextInt();
     if(n<0) break;
     if(n==0) System.out.printf("NO\n");
     else System.out.printf("%s\n",f[n]?"YES":"NO");
   }
  }	
}