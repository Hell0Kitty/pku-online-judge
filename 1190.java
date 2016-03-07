import java.util.Scanner;
public class Main {
static int end,min;   
static int M,S;
static int dfs(int v,int m,int lastr,int lasth)   
{   
    if(m==0)   
    {   
        //当层数为0时若剩余体积不为0,说明此次搜索不成功,应返回   
        if(v>0||v<0)   
            return 0;   
        else  
        {   
            //为0,则题目必有解,判断当前外表面积是否比已经得到的最小面积小,若小则置换.   
            end=1;   
            if(min<S)   
                S=min;   
            return 0;   
        }   
    }   
    int i,t=0,j,k,temp;   
    //计算m层最小的体积   
    for(i=1;i<=m;i++)   
        t+=i*i*i;   
    //若当前体积比最小体积还小,返回   
    if(v<t)   
        return 0;   
    t-=m*m*m;   
    int maxr,maxh;   
    //计算当前最底层所能够达到的最大半径.   
    maxr=(int)Math.sqrt((v-t)*1.0/m)<lastr?(int)Math.sqrt((v-t)*1.0/m):lastr;   
    for(i=maxr;i>=m;i--)   
    {   
        //计算确定半径的情况下能够达到的最大高度   
        maxh=(v-t)/(i*i)<lasth?(v-t)/(i*i):lasth;   
        //搜索   
        for(j=maxh;j>=m;j--)   
        {   
            temp=0;   
            //根据当前最底层确定m层蛋糕能达到的最大体积.   
            for(k=0;k<=m-1;k++)   
                temp+=(i-k)*(i-k)*(j-k);   
            //比最大体积还大,肯定会有剩余,返回   
            if(v>temp)   
                break;   
            int tempv=v-i*i*j;   
            //第一层时要加上上表面的面积   
            if(m==M)   
            {   
                if(i*i<S)   
                min=i*i;   
                else  
                {   
                    tempv=v;   
                    continue;   
                }   
            }   
            //加上侧面积,对每一层都适用   
            min+=2*i*j;   
            //若当前得到的面积已经大于已知的最小外表面积,下面的就不用再搜索了,直接返回   
            if(min>S)   
            {   
                tempv=v;   
                min-=2*i*j;   
                continue;   
            }   
            dfs(tempv,m-1,i-1,j-1);   
            //回溯后要恢复数据   
            min-=2*i*j;   
        }   
    }   
    return 0;   
}   

public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
 ///经典搜索,还可以继续剪枝优化   
//S表示最小面积   
int N;   
//end初始为0,有解则变为1.min用来表示每次成功搜索时蛋糕的外表面积   
//v表示当前剩余的体积,m表示剩余蛋糕的层数,lastr表示已经确定的上一层蛋糕的半径,lasth同理   
    
    while(sc.hasNext())   
    {  
       N=sc.nextInt();
       M=sc.nextInt();
 
        int t=0;   
        end=0;   
        S=100000;   
        dfs(N,M,1000,1000);   
        if(end==0)   
            S=0;   
        System.out.printf("%d\n",S);   
    }   
   }
}  
