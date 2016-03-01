//* @author:
import java.util.*;
import java.math.*;
import java.io.FileReader;
class Node{
    int x,y,z;
}
public class Main {
    static int []mark=new int[1010];
    static double []dis=new double[1010];
    static int []from=new int [1010];
    static double sumup,sumdown;
    static double [][]up=new double [1010][1010];
    static double [][]down=new double [1010][1010];
    static double [][]map=new double [1010][1010];
    static double dist(double x1,double y1,double x2,double y2)
    {
        return Math.sqrt((double)(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    static void prim(int n)
    {
        Arrays.fill(mark, 0);
        mark[1]=1;dis[1]=0;
        sumup=sumdown=0;
        for (int i=2;i<=n;i++) {
            dis[i]=map[1][i];
            from[i]=1;
        }
        for (int i=1;i< n;i++) {
            double min=1e100;
            int sit=0;
            for (int j=1;j<=n;j++) if (mark[j]==0&&dis[j]< min) {
                min=dis[j];
                sit=j;
            }
            mark[sit]=1;
            sumup+=up[sit][from[sit]];
            sumdown+=down[sit][from[sit]];
            for (int j=1;j<=n;j++) if (mark[j]==0&&dis[j]>map[sit][j]) {
                dis[j]=map[sit][j];
                from[j]=sit;
            }
        }
    }
    public static void main(String[] args) throws Exception{
        Scanner in=new Scanner(System.in);
        Node []a=new Node[1010];
        while (true) {
            int n=in.nextInt();
            if (n==0) break;
            for (int i=1;i<=n;i++) {
                a[i]=new Node();
                a[i].x=in.nextInt();
                a[i].y=in.nextInt();
                a[i].z=in.nextInt();
            }
            double mid=30;
            for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
                up[i][j]=up[j][i]=Math.abs(a[i].z-a[j].z);
                down[i][j]=down[j][i]=dist(a[i].x,a[i].y,a[j].x,a[j].y);
            }
            double lastmid=30;
            while (true) {
                for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
                    map[j][i]=map[i][j]=up[i][j]-mid*down[i][j];
                }
                prim(n);
                mid=sumup/sumdown;
                if (Math.abs(mid-lastmid)< 0.001) break;
                lastmid=mid;
            }
            System.out.printf("%.3f\n",mid);
        }
    }
}

