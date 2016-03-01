import java.util.Scanner;
import java.util.Arrays;
public class Main{

static double lfabs(double x)
{
    return x>0?x:-x;
}

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  double sat[][]=new double[100][3];
  double xa,xb,ya,yb,za,zb,s,s1,s2,s3,angle,r=20000/3.14159265;
  int k,m,i,j,flag=0,num;
    while(sc.hasNext())
    {
       k=sc.nextInt();
       m=sc.nextInt();
       if(k==0&&m==0) break;
        num=0;
        for(i=0;i< k;i++){
          sat[i][0]=sc.nextDouble();
          sat[i][1]=sc.nextDouble();
          sat[i][2]=sc.nextDouble();
        }
        for(i=0;i< m;i++)
        {
            flag=0;
            xb=sc.nextDouble();
            yb=sc.nextDouble();
            zb=sc.nextDouble();
            for(j=0;j< k;j++)
            {
                xa=sat[j][0];ya=sat[j][1];za=sat[j][2];
                s1=Math.sqrt(xa*xa+ya*ya+za*za);
                s2=Math.sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya)+(zb-za)*(zb-za));
                if(s2<=Math.sqrt(s1*s1-r*r)){flag=1;break;}
            }
            if(flag!=0)num++;
        }
        System.out.printf("%d\n",num);
    }
  }
}

