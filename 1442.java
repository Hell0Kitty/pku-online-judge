import java.util.Scanner;

  public class Main{
   int tree1[];//大顶堆   
   int k1;  
   int tree2[];//小顶堆   
   int k2;  
   int M, N;  
   int A[];  
  
  public Main(){
   }

  //tree:大顶堆
  void build1(int[] tree, int k)  //从k开始，大堆向上调整到根
  {  
    int p = k;  
    while(p != 1)  
    {  
        if(tree[p] > tree[p / 2])  //如果大于父亲
        {  
            int temp = tree[p];  //交换
            tree[p] = tree[p / 2];  
            tree[p / 2] = temp;  
        }  
        p = p / 2;  //指向父亲
    }  
}  
  //tree:小顶堆
void build2(int[] tree, int k)  //从k开始，小堆向上调整
{  
    int p = k;  
    while(p != 1)  
    {  
        if(tree[p] < tree[p / 2])  //如果小于交亲
        {  
            int temp = tree[p];  //交换
            tree[p] = tree[p / 2];  
            tree[p / 2] = temp;  
        }  
        p = p / 2;  //指向父亲
    }  
}  
  
//tree:大顶堆
void update1(int[] tree, int k){//向下调整大顶堆的根.  
    int p = 1;  //指向根
    while(2 * p <= k)  
    {  
        int son;  
        if(2 * p == k || tree[2 * p] > tree[2 * p + 1])  
            son = 2 * p;  
        else  
            son = 2 * p + 1;  
        if(tree[p] < tree[son])  //如果父节点的值小于左右儿子中最大者，交换
        {  
            int temp = tree[p];  
            tree[p] = tree[son];  
            tree[son] = temp;  
        }  
        p = son;  //指向儿子节点
    }  
}  
  
//tree:小顶堆
void update2(int[] tree, int k)  //向下调整小顶堆的根,直到k
{  
    int p = 1;  
    while(2 * p <= k)  
    {  
        int son;  
        if(2 * p == k || tree[2 * p] < tree[2 * p + 1])  //取左右儿子中的较小者
            son = 2 * p;  
        else  
            son = 2 * p + 1;  
        if(tree[p] > tree[son])  //如果父节点的值大于左右儿子中最大者，交换
        {  
            int temp = tree[p];  
            tree[p] = tree[son];  
            tree[son] = temp;  
        }  
        p = son;  
    }  
}  
  
  public void  go(){  
   Scanner in=new Scanner(System.in);
    while(in.hasNext())  
    {  
     M=in.nextInt();
     N=in.nextInt();

     A=new int[M+1];
     tree1=new int[M+1];
     tree2=new int[M+1];
     for(int i = 1; i <= M; ++ i)  
            A[i]=in.nextInt();//将M个元素全部读入A
  
        int pre = 0;  
        k1 = k2 = 0;  
        for(int i = 1; i <= N; ++ i)  
        {  
            int a=in.nextInt();  
            for(int j = pre + 1; j <= a; ++ j)  //从A中读入前a个元素到tree2
            {  
                tree2[++k2] = A[j];  //读一个,调整一个
                build2(tree2, k2);  //调整tree2使之成为最小堆
                  
            }  
            pre = a;  
            tree1[++ k1] = tree2[1];  //将最小堆的堆顶元素放入tree1中
            build1(tree1, k1);  //调整tree1使之成为最大堆
            tree2[1] = tree2[k2 --];  //删除最小堆的堆顶元素,最小堆的最后一个元素放到堆顶
            update2(tree2, k2);  //调整
            while(k2 != 0 && tree1[1] > tree2[1])  
            {  
                int temp = tree1[1];  
                tree1[1] = tree2[1];  
                tree2[1] = temp;  
                update1(tree1, k1);  
                update2(tree2, k2);  
            }  
            System.out.printf("%d\n", tree1[1]);  
        }         
    }
  }  
    
  public static void main(String args[]){
       Main ma=new Main();
       ma.go();
  }
}