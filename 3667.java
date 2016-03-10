import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;


class point
{
    int l,r,max,cov;
}
 public class Main{
  // static int  MAX = 50010;


   point p[];
   public Main(){
      p=new point[131070];
      for(int i=0;i< p.length;i++)
         p[i]=new point();
   }

  void push_up(int l,int r,int rt)
  {
    p[rt].l = p[rt<<1].l;
    p[rt].r = p[rt<<1|1].r;
    int mid = r+l>>1;
    if(p[rt].l==mid-l+1) p[rt].l+=p[rt<<1|1].l;
    if(p[rt].r==r-mid) p[rt].r+=p[rt<<1].r;
    p[rt].max =Math.max(Math.max(p[rt<<1].max,p[rt<<1|1].max),p[rt<<1].r+p[rt<<1|1].l);
 }

  void push_down(int l,int r,int rt)
  {
    if(p[rt].cov!=-1)
    {
        p[rt<<1].cov = p[rt<<1|1].cov = p[rt].cov;
        if(p[rt].cov==1)
        p[rt<<1].l = p[rt<<1|1].l = p[rt<<1].r = p[rt<<1|1].r = p[rt<<1].max = p[rt<<1|1].max = 0;
        else
        {
            int mid = r+l>>1;
            p[rt<<1].l = p[rt<<1].r = p[rt<<1].max = mid-l+1;
            p[rt<<1|1].l = p[rt<<1|1].r = p[rt<<1|1].max = r-mid;
        }
        p[rt].cov = -1;
    }
 }

 void build(int l,int r,int rt){
    p[rt].l = p[rt].r = p[rt].max = r-l+1;
    p[rt].cov = -1;
    if(l==r)
    {
        return;
    }
    int mid = r+l>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
 }

 //a==1,填满[L,R],a=0清空区间[L,R]
 void update(int a,int L,int R,int l,int r,int rt)
 {
    if(L<=l&&R>=r)
    {
        if(a==1)
          p[rt].l = p[rt].r = p[rt].max = 0;
        else
          p[rt].l = p[rt].r = p[rt].max = r-l+1;
        p[rt].cov = a;
        return;
    }
    int mid = r+l>>1;
    push_down(l,r,rt);
    if(L<=mid) update(a,L,R,l,mid,rt<<1);
    if(R>mid) update(a,L,R,mid+1,r,rt<<1|1);
    push_up(l,r,rt);
 }

  int query(int a,int l,int r,int rt)
  {
    if(l==r)
    {
        return l;
    }
    int mid = r+l>>1;
    push_down(l,r,rt);
    if(p[rt<<1].max>=a) return query(a,l,mid,rt<<1);
    if(p[rt<<1].r+p[rt<<1|1].l>=a) return mid-p[rt<<1].r+1;
    return query(a,mid+1,r,rt<<1|1);
 }

  public int getMax(){
    return p[1].max;
  }
  public static void  main(String args[]) throws IOException{

    StreamTokenizer st = new StreamTokenizer(new BufferedReader(
      new InputStreamReader(System.in)));
      PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));


    int n,m,k,x,y;
    while(st.nextToken() != StreamTokenizer.TT_EOF)
    {

         n= (int) st.nval;
          st.nextToken();
         m= (int) st.nval;
         Main ma=new Main();

        ma.build(1,n,1);
        while(m-->0)
        {
            st.nextToken();
            k=(int) st.nval;
            if(k==1)
            {
                 st.nextToken();
                x= (int) st.nval;
                if(ma.getMax()< x) System.out.println("0");
                else
                {
                    int tmp =ma.query(x,1,n,1);
                    System.out.printf("%d\n",tmp);
                    ma.update(1,tmp,tmp+x-1,1,n,1);
                }
            }
            else
            {
                 st.nextToken();
                x=(int) st.nval;
                 st.nextToken();
                y=(int) st.nval;
                ma.update(0,x,x+y-1,1,n,1);
            }
        }
       out.flush();
    }
   }
}

