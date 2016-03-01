import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.Arrays;

   class TNode implements Comparable{
    int s;//左端点
    int e;//右端点
    int label;//牛的序号
    public int compareTo(Object o) {
       int v=((TNode)o).e;
       if(this.e!=v) //按右端点降序排列
         return v-this.e;
       return this.s-((TNode)o).s;//右端点相等,按左端点升序排序
    }

    public String toString(){
        return ("["+s+","+e+"]");
    }
  }

 public class Main{
   static  int N=100015;
   TNode[] cow;
   int cal[];//树状数组
   int res[];
   int maxn;

  public Main(){

     }



  private int lowbit(int t){//计算cal[t]展开的项数
   return t&(-t);
  }

  private int Sum(int k){ //求前k项的和.
   int sum=0;
    while(k>0){
       sum+=cal[k];
       k=k-lowbit(k);
    }
    return sum;
  }

  private void update(int i,int x){    //增加某个元素的大小,给某个节点 i 加上 x
      while(i<=maxn){
        cal[i]=cal[i]+x; //更新父节点
        i=i+lowbit(i);
     }
    }




  public static void  main(String args[]) throws IOException{
        Main ma=new Main();
        ma.go();
   }

    public void go() throws IOException{

      StreamTokenizer st = new StreamTokenizer(new BufferedReader(
      new InputStreamReader(System.in)));
      PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

      while(true) {
       st.nextToken();
      int n= (int) st.nval;    //牛的个数
      if(n==0) break;

     cow=new TNode[N];
     cal=new int[N];
     res=new int[N];
     for(int i=0;i< N;i++){
       cow[i]=new TNode();
      // cal[i]=0;
      }
      for(int i=0;i< n;i++) {//读入牛的吃草区间
            st.nextToken();
           cow[i].s=(int) st.nval;
             st.nextToken();
           cow[i].e=(int) st.nval;
           cow[i].s++;
           cow[i].e++;
           cow[i].label=i;//牛的原始序号
           if(cow[i].e>maxn) maxn=cow[i].e;//最大右端点
      }

        Arrays.sort(cow);//排序

     // for(int i=0;i< n;i++)
       // System.out.println(cow[i]);

      for(int i=0;i< n;i++) {
           if(i!=0&&cow[i].s==cow[i-1].s&&cow[i].e==cow[i-1].e)//两头牛有相同的吃草区间
                res[cow[i].label]=res[cow[i-1].label];//它们有相同的答案
            else res[cow[i].label]=Sum(cow[i].s);//统计比cow[i].label这头牛强的牛的数目
            update(cow[i].s,1);//更新
        }
        System.out.printf("%d",res[0]);
        for(int i=1;i< n;i++) System.out.printf(" %d",res[i]);
        System.out.println();
    }
  }
}

