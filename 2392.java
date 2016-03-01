import java.util.Scanner;
import java.util.Arrays;
public class Main{
  private int k;
  private Block block[];
  private boolean access[]=new boolean[400001];

   public Main(int k,Block block[]){
    this.k=k;
    this.block=block;
  }

  private int doIt(){
   int maxs=0;
   access[0]=true;
   Arrays.sort(block);
   for(int i=0;i< k;i++)
    {
       int t=0;
       int tmp=maxs;
       for(int j=maxs;j>=t;j--)
       {
          if(access[j])
           for(int h=1;h<=block[i].c;h++)
           {
                  int x=h*block[i].h+j;
                  if(x>block[i].a) break;
                  if(tmp< x) tmp=x;
                  access[x]=true;
           }
       }
       maxs=tmp;
    }
    return maxs;
   }

   public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
     int k=sc.nextInt();
     Block b[]=new Block[k];
     for(int i=0;i< k;i++){
       b[i]=new Block();
       b[i].h=sc.nextInt();
       b[i].a=sc.nextInt();
       b[i].c=sc.nextInt();
     }
     Main m=new Main(k,b);
     System.out.println(m.doIt());
   }
}

class Block implements Comparable{//石头类型
  int h;//石头的高度
  int a;//最大建造高度
  int c;//这种石头的数量

  public Block(){
    h=0;
    a=0;
    c=0;
  }

  public Block(int h,int a,int c){
     this.h=h;
     this.a=a;
     this.c=c;
  }

   public int compareTo(Object o){
        Block bl = (Block)o;
        return (int)(this.a - bl.a);
    }


 public String toString(){
        return "( "+ h +"-"+ a +"-"+c +" )";
    }
 }

