/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main {


 public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
    int g[][]=new int[52][52];
    int ca,i,j,k,n,r,x,y,dir;
    ca=sc.nextInt();
    while ((ca--)!=0)
    {
        n=sc.nextInt();
        r=sc.nextInt();
        for(i=0;i< g.length;i++)
          Arrays.fill(g[i],0);
        for (i=0;i< r;i++)
        {
            x=sc.nextInt();
            y=sc.nextInt();
            g[x][y]=1;
        }
        for (i=0;i<=n+1;i++)
        g[0][i]=g[n+1][i]=g[i][0]=g[i][n+1]=-1;
        x=sc.nextInt();
        y=sc.nextInt();
        if (y==0) dir=0; else
        if (x==0) dir=1; else
        if (y==n+1) dir=2; else dir=3;
        x+=dx[dir];
        y+=dy[dir];
        while (g[x][y]!=-1)
        {
            if (g[x][y]!=0) dir=(dir+1)%4;
            x+=dx[dir];
            y+=dy[dir];
        }
        System.out.printf("%d %d\n",x,y);
    }
  }
}

