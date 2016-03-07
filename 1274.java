import java.io.*;
import java.util.*;
public class Main
{
            static int m,n;
            static boolean[] flag;
            static int[] occ;
            static int[][] adj;
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    while(cin.hasNext())
                    {
                    	n=cin.nextInt();
                    	m=cin.nextInt();
                    	adj=new int[n+1][m+1];
                    	for(int i=0;i<n;i++)
                    	{
                    		int a=cin.nextInt();
                    		while(a--!=0)
                    		{
                    			adj[i+1][cin.nextInt()]=1;
                    		}
                    	}
                    	int count=0;
                    	occ=new int[m+1];
                    	for(int i=1;i<=n;i++)
                    	{
                    		flag=new boolean[m+1];
                    		if(find(i))
                    		{
                    			count++;
                    		}
                    		
                    	}
                    	System.out.println(count);
                    }
            }
            
            public static boolean find(int i)
            {
            	for(int j=1;j<=m;j++)
            	{
            		if(!flag[j]&&adj[i][j]==1)
            		{
            			flag[j]=true;
            			if(occ[j]==0||find(occ[j]))
            			{
            				occ[j]=i;
            				return true;
            			}
            		}
            	}
            	return false;
            }
}