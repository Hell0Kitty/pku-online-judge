import java.util.Scanner;
import java.util.Arrays;
public class Main{
 static int c[]=new int[11];//c[i]存放边长为i的小正方形的个数
 static int d[]=new int[41];//d[i]表示第i行填入小正方形后的最大横坐标
 static int s,n,sum;
 static boolean  ok;

public static void main(String args[])
{
    int t,it,i,tp;
    Scanner sc=new Scanner(System.in);
    t=sc.nextInt();//测试次娄

    for(it=1;it<=t;it++)//循环进行每一次测试
    {
        s=sc.nextInt();//“盘子”大正方形的边长
        n=sc.nextInt();//小正方形的个数
        Arrays.fill(c,0);//每次测试前清空
         ok=false;
        for(i=1;i<=40;i++) d[i]=1;//
        sum=0;
        for(i=1;i<=n;i++)//从命令行依次读入小正方形的边长
        {
            tp=sc.nextInt();
            c[tp]++;//边长为tp的小正方形的个数增加1
            sum+=tp*tp;//统计面积
        }
        if(sum!=s*s) ok=false;//如果所有小正方形面积之和不等于“盘子”面积
        else {ok=false;dfs(0);}//深度优先搜索

        if(ok) System.out.println("KHOOOOB!");
        else System.out.println("HUTUTU!");
    }
   }

  public static void dfs(int a)
{
    int i,j,put,p=0;
    boolean f;
    if(a==n) {//如果对所有的n个小正方形搜索完毕。
       ok=true;
       return;
    }

    //寻找未填的横坐标最小的点的纵坐标
    for(i=1,put=41;i<=s;i++){
        if(d[i]< put) {
          put=d[i];//put:横坐标
          p=i;//p:纵坐标
       }
    }

     //从横坐标最小的那列开始，从大到小搜索能填入的小正方形
    for(i=10;i>=1;i--)
        if(c[i]>0 && put+i-1<=s && p+i-1<=s)//在坐标(put,p)处能放得下小正方形c[i]
        {
            for(j=p,f=true;j<=p+i-1;j++)
                if(d[j]>put) {f=false;break;}
            if(f)
            {
                for(j=p;j<=p+i-1;j++) d[j]+=i;//标记第i行填入小正方形后的最大横坐标

                c[i]--;
                dfs(a+1);
                c[i]++;//回朔
                for(j=p;j<=p+i-1;j++) d[j]-=i;
            }
        }
    }
}

