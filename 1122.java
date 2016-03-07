import java.util.Arrays;
import java.util.Scanner;
public class Main
{
    static final int Inf=9999999;
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int a=in.nextInt();
        int[][] p=new int[a][a];
        for(int i=0;i< a;i++)
            for(int j=0;j< a;j++)
                p[i][j]=in.nextInt();
        int loc =in.nextInt()-1;
        boolean[] bb=new boolean[a];
        bb[loc]=true;
        int[] time=new int[a];
        int[] path=new int[a];
        for(int i=0;i< a;i++)
        {
            if(p[i][loc]!=-1)
            {
                time[i]=p[i][loc];
                path[i]=loc;
            }
            else
            {
                time[i]=Inf;
                path[i]=-1;
            }
        }
        for(int i=0;i< a-1;i++)
        {
            int min=Inf,tag=loc;
            for(int j=0;j< a;j++)
            {
                if(!bb[j]&&time[j]< min)
                {
                    min=time[j];
                    tag=j;
                }
            }
            bb[tag]=true;
            for(int j=0;j< a;j++)
                if(!bb[j]&&p[j][tag]!=-1&&time[tag]+p[j][tag]< time[j])
                {
                    time[j]=time[tag]+p[j][tag];
                    path[j]=tag;
                }
        }
        he[] arr=new he[a];
        int len=0;
        while(in.hasNextInt())
        {
            int u=in.nextInt();
            arr[len++]=new he(time[u-1],u-1);
        }
        System.out.println("Org Dest    Time    Path");
        Arrays.sort(arr,0,len);
        for(int i=0;i< len;i++)
        {
         System.out.print((arr[i].loc+1)+"  "+(loc+1)+" "+arr[i].time+" "+(arr[i].loc+1));
         if(arr[i].loc==loc){
                System.out.println();
                continue;
            }
            int u=path[arr[i].loc];
            while(true)
            {
                System.out.print("  "+(u+1));
                if(u==loc)break;
                u=path[u];
            }
            System.out.println();
        }
    }
}
class he implements Comparable
{
    int time,loc;
    public he(int t,int l)
    {
        time=t;
        loc=l;
    }
    @Override
    public int compareTo(he arg0) {
        // TODO Auto-generated method stub
        return time-arg0.time;
    }
}


