import java.util.Scanner;
public class Main {

 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
    double b,v,e,f,t[]=new double[101],t1;
    int n,a[]=new int[101],r;
    int i,j,k,dis;
    while(sc.hasNext())
    {
        n=sc.nextInt();
        if(n==0) break;

        a[0]=0;
        for(i=1;i<=n;i++)
           a[i]=sc.nextInt();

        b=sc.nextDouble();
        r=sc.nextInt();
        v=sc.nextDouble();
        e=sc.nextDouble();
        f=sc.nextDouble();

        t[0]=0;
        for(i=0;i< n;i++)
        {
            if(i==0)t1=0;else t1=b;
            for(j=i+1;j<=n;j++)
            {
                for(k=a[j-1];k< a[j];k++)
                {
                    dis=k-a[i];
                    if(dis>=r) t1+=1/(v-e*(dis-r));
                    else t1+=1/(v-f*(r-dis));
                }
                if(i==0||t1+t[i]< t[j])t[j]=t[i]+t1;
            }
        }
        System.out.printf("%.4f\n",t[n]);
    }
   }
}

