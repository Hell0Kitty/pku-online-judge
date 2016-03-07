import java.util.*;
import java.io.*;
/*
 *【题意简述】信道分配。给定一个无向图，为每顶点填上颜色，要求满足相邻的顶点颜色不同，问最少的颜色数是多少?
 *【分析】利用四色定理，直接枚举颜色数+DFS，其中DFS是暴力枚举每个顶的颜色，以便找到一个可行解。 
 */
public class Main{
    
    public static int[][] g=new int[26][26];
    
    public static int solve(int n){
        int i,j,cnum;
        boolean tag=true;
        // 无边图只用1色即可
        for(i=0;i<n && tag;i++){
            for(j=i+1;j<n && tag;j++){
                if(g[i][j]==1) 
                    tag=false;
            }
           }
        if(tag) 
            return 1;
        
        for(cnum=2;cnum<=4;cnum++)    // 枚举答案+dfs
        {
            int[] x=new int[n];
            Arrays.fill(x,-1);
            if(DFS(x,0,cnum,n)) 
                return cnum;
        }
        return -1;
    }
    
    //DFS的复杂度是颜色数^顶点数(4^26，其中可行性剪枝剪掉了很多分支) 
    public static boolean DFS(int[] x,int vnum, int cnum,int n){
        if(vnum == n) return true;    // v的顶点都上色，可行解
        for(int i=0;i<cnum;i++){    // 如果某个顶点没有颜色填，返回上一层
            x[vnum] = i;
            if(check(vnum,x,i,n))         
                if(DFS(x,vnum+1,cnum,n)) // 合法，枚举下一个顶点
                    return true;
        }
        return false;
    }

    // 判断相邻的顶点是否有涂过这种颜色
    public static boolean check(int vnum,int[] x,int t,int n){
        boolean find=true;
        for(int i=0;i<n && find;i++){
            if(g[vnum][i]==1 && x[i]==t)
                find=false;
        }
        return find;
    }
    
    public static void main(String rgs[]) throws Exception
    {  
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int i,j,n=cin.nextInt();
        while(n!=0){            
            for(i=0;i<n;i++)
                Arrays.fill(g[i],0);        
            for(i=0;i<n;i++){
                String s = cin.next();
                for(j=2;j<s.length();j++)
                    g[i][s.charAt(j)-'A']=1;
            }
            int count=solve(n);
            if(count==1)
                System.out.println(count+" channel needed.");
            else
                System.out.println(count+" channels needed.");
            n=cin.nextInt();
        }
    }
}