import java.util.Scanner;
import java.util.Arrays;
public class Main{
  static final int maxn=100;
  private int a[]=new int[maxn],p[]=new int[maxn],f[]=new int[maxn];

  private  int min(int a,int b){
	return a<b?a:b;
  }

  public int dp(int x){
	if(x<0)return 0;
	if(f[x]!=-1)return f[x];
	if(x==0)return f[x]=(a[0]+10)*p[0];
	int c=(10+a[x])*p[x],res=c+dp(x-1);
	for(int i=x-1;i>=0;i--){
		c+=p[x]*a[i];
		res=min(c+dp(i-1),res);
	}
	return f[x]=res;
}
 public static void main(String args[]){
    
    Scanner sc=new Scanner(System.in);
  
	int times=sc.nextInt();
	while((times--)!=0){
		int n=sc.nextInt();
              Main m=new Main();
		for(int i=0;i<n;i++){
               m.a[i]=sc.nextInt();
               m.p[i]=sc.nextInt();
             }
             Arrays.fill(m.f,-1);
		System.out.printf("%d\n",m.dp(n-1));
	}
  }
}

