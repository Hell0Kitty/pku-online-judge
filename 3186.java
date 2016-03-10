//* @author: 82638882@163.com
import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    String s=in.readLine();
    int a=Integer.parseInt(s);
    int[] arr=new int[a];
    int[][] ds=new int[a][a];
    for(int i=0;i< a;i++)
    {
        s=in.readLine();
        arr[i]=Integer.parseInt(s);
    }
    System.out.println(f(arr,0,a-1,ds));

   }

 public static int f(int[] arr,int l,int r,int[][] ds)
 {
    if(ds[l][r]!=0) return ds[l][r];
    int n=arr.length;
    if(l==r) return ds[l][l]=n*arr[l];
    int w=f(arr,l+1,r,ds)+(n-r+l)*arr[l];
    int o=f(arr,l,r-1,ds)+(n-r+l)*arr[r];
    ds[l][r]=Math.max(w, o);
    return ds[l][r];
 }
}

