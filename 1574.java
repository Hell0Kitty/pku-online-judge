import java.util.*;

public class Main {
  private int x[]=new int[7];
  private int y[]=new int[7];
  private int z[]=new int[7];
  private int a[]=new int[7],b[]=new int[7],c[]=new int[7],ax[]=new int[7],use[]=new int[7];
  private int max;

 public Main(int x[],int y[],int z[]){
    this.x=x;
    this.y=y;
    this.z=z;
    max=0;
   for(int i = 0;i < 7;i ++) use[i] = 0;
  }

public int  dfs(int p){
for(int i = 1;i <= 6;i ++) //每个三角形有6种放法
{
   if(use[i]!=0) continue;//前面三角形放过的位置不等再放
   for(int j = 1;j <= 3;j ++)//每个三角形又可进行旋转
   {
    if(j == 1) {a[p] = x[i];b[p] = y[i];c[p] = z[i];}
    if(j == 2) {a[p]=y[i];b[p]=z[i];c[p] = x[i];}
    if(j == 3) {a[p] = z[i];b[p] = x[i];c[p] = y[i];}
    if(p != 1 && c[p] != b[p-1]) //这点很关键,必须边长相等
     continue;
    if(p == 1)
     ax[p] = a[p];
    else
     ax[p] = ax[p-1] + a[p];
    use[i] = 1;
    if(p<6)
     dfs(p + 1);
    else
    {
     if(b[p] == c[1]) // 同上,这点容易忽视
     {
      if(max < ax[p]) 
       max = ax[p];//取最优值
     }
    }
   }
   use[i] = 0;
}
 return max;
}

  public static void main(String[] args){
   Scanner in = new Scanner(System.in);
   char ch;
   int x[]=new int[7],y[]=new int[7],z[]=new int[7];
   while(in.hasNext()){
   
   for(int i = 1;i <= 6;i ++) {
    x[i]=in.nextInt();
    y[i]=in.nextInt();
    z[i]=in.nextInt();
   }
    
    Main m=new Main(x,y,z);
   int max=m.dfs(1);
   if(max == 0)
    System.out.printf("none\n");
   else
    System.out.printf("%d\n",max);
    ch=in.next().charAt(0);
   if(ch=='$')
       break;
  }
 }
}