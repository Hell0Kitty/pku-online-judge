import java.util.*;
 public class Main{
   static final int INF=100000;
   Point arr[];

   int v,r,s,e,len;
   int map[][];
   boolean f[];
   int x[];//用于记录从起点到终点的路径
   int ii;
   static int counter = 0;

   public Main(int v,int s,int e,int len,int[][] map){
      this.v=v;//顶点数
      this.s=s;//起点
      this.e=e;//终点
      this.len=len;//距离限定
      this.map=map;//图的邻接矩阵
      f =new boolean[v+1];
      x=new int[v+1];
      arr=new Point[4000];
      for(int i=0;i< 4000;i++)
          arr[i]=new Point();
   }

  //ind:旅游的步骤，从0(起点）开始，
  //sum:旅游的距离
  //cur:旅游的当前点
void dfs(int cur , int sum , int ind){
    if( sum > len ) return ;
    if( cur == e){
        arr[ii].sum = sum;
        for(int i=0;i< ind;i++)
        {
           // arr[ii]=new Point();
            arr[ii].num[i] = x[i];
        }
        arr[ii++].jj = ind;
        return ;
    }
    for(int i=1;i<=v;i++)
    {
        if( !f[i] && map[cur][i] < INF )
        {
            if( sum + map[cur][i] <= len )
            {
                f[i] = true;
                x[ind++] = i;
                dfs(i , sum+map[cur][i],ind);
                f[i] = false;
                x[ind--] = 0;
            }
        }
    }
}

  public static void main(String[] args){
   Scanner in=new  Scanner(System.in);
   int v, r,s, e,len;
   int[][] map;
    while(true)
    {
        v=in.nextInt();
        if(v==-1) break;
        r=in.nextInt();
        map=new int[v+1][v+1];//邻接矩阵
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                map[i][j] = INF;
            }
        }
        for(int i=0;i< r;i++)
        {
            int a,b,c;
            a=in.nextInt();
            b=in.nextInt();
            c=in.nextInt();
            map[a][b] = map[b][a] = c;
        }
         s=in.nextInt();
         e=in.nextInt();
         len=in.nextInt();
         Main m=new Main(v,s,e,len,map);
         m.go();
      }
 }

      public void go(){

        System.out. printf("Case %d:\n",++counter);
         f[s] = true;
         x[0] = s;//旅游的步骤，从0(起点）开始
         ii = 0;
         dfs(s,0,1);//旅游的步骤，第1步
        if(ii==0) System.out.printf(" NO ACCEPTABLE TOURS\n");
        else
        {
            Arrays.sort(arr ,0, ii ,new SampleComparator());
            for(int i=0;i< ii;i++)
            {
                System.out.printf(" %d: ",arr[i].sum);
                for(int j=0;j< arr[i].jj;j++)
                {

                    System.out.printf("%d ",arr[i].num[j]);
                }
                System.out.println();
            }
        }
        System.out.println();
    }

}


 class Point{
    int jj;//从起点到此点经过的城市数目
    int sum ;//从起点到此点的距离
    int num[]=new int[25];//从起点到此点的路径
 }

 class SampleComparator implements Comparator {
    public int compare(Object o1, Object o2) {
      Point a=(Point)o1;
      Point b=(Point)o2;
      if( a.sum != b.sum ){
         if(a.sum < b.sum) return -1;
         else return 1;
      }
      else{
        int len1 = a.jj;
        int len2 = b.jj;

        for(int i=0;i< Math.max(a.jj,b.jj);i++)
        {
            if( a.num[i] != b.num[i] ) {
                if(a.num[i] < b.num[i]) return -1;
                else return 1;
             }
        }
        return 0;
      }
   }
}


