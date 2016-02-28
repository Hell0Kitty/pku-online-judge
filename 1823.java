import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

  class Tree{ 
        int ll,rr,mid; 
        int max,cl,cr;//max表示结点管理的区间最大的连续子区间有多大，cl表示区间的最左边有多少连续的区间，cr表示区间的右边有多少连续的子区间 
        int occ;//occ==0表示空，occ=1表示全部入住，occ=-1表示有空有住 
    }
   public class Main{
     Tree tree[]; 
    public Main(){
       tree=new Tree[32766];
       for(int i=0;i<tree.length;i++){
            tree[i]=new Tree();
       }
    }
    

    void build(int id,int ll,int rr){ 
        tree[id].ll=ll;tree[id].rr=rr;tree[id].mid=(ll+rr)>>1; 
        //刚开始建树，都是空的，所以可以这样写 
        tree[id].max=tree[id].cl=tree[id].cr=rr-ll+1; 
        tree[id].occ=0; 
        if(ll==rr)return; 
        build(id<<1,ll,tree[id].mid); 
        build(id<<1|1,tree[id].mid+1,rr); 
    } 

    void push_down(int id,int sign){//sign=1表示入住，sign=0表示退房 
        tree[id].occ=-1;//表示有空有住 
        tree[id<<1].occ=tree[id<<1|1].occ=sign;//表示全空或者全住 
        if(sign==1){ 
            tree[id<<1].cl=tree[id<<1|1].cl=tree[id<<1].cr=tree[id<<1|1].cr=0; 
            tree[id<<1].max=tree[id<<1|1].max=0; 
        }else{ 
            int len=tree[id<<1].rr-tree[id<<1].ll+1; 
            tree[id<<1].cl=tree[id<<1].cr=len; 
            tree[id<<1].max=len; 
            len=tree[id<<1|1].cr=tree[id<<1|1].rr-tree[id<<1|1].ll+1; 
            tree[id<<1|1].cl=len; 
            tree[id<<1|1].max=len; 
        } 
    } 

    //更新区间 
    void update(int id ,int ll,int rr,int sign){//sign=1入住，sign=0表示退房 
        if(tree[id].ll==ll&&tree[id].rr==rr){//找到区间 
            tree[id].occ=sign; 
            int len=tree[id].rr-tree[id].ll+1; 
            if(sign==1) len=0; 
            tree[id].cl=tree[id].cr=len; 
            tree[id].max=len; 
            return; 
        } 
        if(tree[id].occ==1)
            push_down(id,1);//执行到这行代码意味着 tree[id]的子区间要更改了，所以需要执行一次push_down 
        if(tree[id].occ==0)
          push_down(id,0);
        if(rr<=tree[id].mid){ 
            update(id*2,ll,rr,sign); 
        }else if(ll>tree[id].mid){ 
            update(id*2+1,ll,rr,sign); 
        }else{ 
            update(id*2,ll,tree[id].mid,sign);
            update(id*2+1,tree[id].mid+1,rr,sign); 
        } 
        //子区间更新了,必须更新父区间
        //需要修改的就只有3个值：max,cl,cr 分别代表最长连续个数为多少，最左边有多少个空闲，最右边有多少个空闲 
        if(tree[id].occ==-1){//表示有空有住 
            if(tree[id<<1].occ==0){ 
                tree[id].cl=tree[id*2].cl+tree[id<<1|1].cl; 
            }else{ 
                tree[id].cl=tree[id<<1].cl; 
            } 
            if(tree[id<<1|1].occ==0){ 
                tree[id].cr=tree[id*2].cr+tree[id<<1|1].cr; 
            }else{ 
                tree[id].cr=tree[id<<1|1].cr; 
            } 
            //求tree[id].max 
            int len=tree[id<<1].cr+tree[id<<1|1].cl; 
            tree[id].max=Math.max(len,Math.max(tree[id<<1].max,tree[id<<1|1].max)); 
        }else{//表示全空或者全住 
            int len; 
            
            if(sign==1)
                len=0;
            else
                len=tree[id].rr-tree[id].ll+1; 
            tree[id].max=tree[id].cl=tree[id].cr=len; 
        } 
        if(tree[id*2].occ==tree[id*2+1].occ) 
            tree[id].occ=tree[id*2].occ; 
    } 

     int getMax(){
       return tree[1].max;
     }

    public static void main(String[] args) throws IOException{

StreamTokenizer st = new StreamTokenizer(new BufferedReader(
				new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

          st.nextToken();

         int n= (int) st.nval;
          
          st.nextToken();
         int p=(int) st.nval;
     //  long start=System.currentTimeMillis();//获取开始时间
         Main ma=new Main();
        int sign; 
        int ll,rr; 
        ma.build(1,1,n); 
        for(int i=0;i<p;i++){ 
              st.nextToken();
            sign=(int) st.nval;
            if(sign==3){ 
               out.printf("%d\n",ma.getMax()); 
            }else{ 
                st.nextToken();
                ll=(int) st.nval;
                st.nextToken();

                rr=(int) st.nval;
                rr=ll+rr-1; 
                if(sign==2)
                  sign=0;
                ma.update(1,ll,rr,sign); 
            } 
        } 
       out.flush();
      }
  } 

