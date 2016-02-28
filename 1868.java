import java.util.Scanner;
public class Main {
  private int n;
  private int a[];

  public Main(int n,int[] a){
   this.n=n;
   this.a=a;
 }
  public boolean doIt(){

 	for(int j=1;j<n/2;j++)
		{
			for(int i=j;i<n-j;i++)
			{
				if((a[i-j]-a[i])*(a[i+j]-a[i])<0)
				{
					return true;
				}
			}
		}
         return false;
	}

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
	while(sc.hasNext())
	{    
           int n=0;
           String s=sc.next();
           if(s.endsWith(":"))
	      n=Integer.parseInt(s.substring(0,s.length()-1));
           if(n==0) break;
            int a[]=new int[n];
	    for(int i=0;i<n;i++){
		int tempno=sc.nextInt();
		a[tempno]=i;
	    }
              Main m=new Main(n,a);
	
		if(!m.doIt())
			System.out.printf("yes\n");
		else
			System.out.printf("no\n");
		
	}
   }
}