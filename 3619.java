import java.util.*;
import java.io.*;
/*
 * n 工作量;
 * s[i] 每分钟可完成的工作量
 * t[i] 一次性连续工作最多坚持的时间
 * r[i] 一次连续工作后需要休息的时间
*/
public class Main{

    public static void main(String rgs[]) throws Exception
    {
        BufferedReader stdin =
            new BufferedReader(
                new InputStreamReader(System.in));
           String line = stdin.readLine();
           StringTokenizer st = new StringTokenizer(line);
           int k,s,t,r,i,j,n,m,l,p;
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for(i=0;i< k;i++){
            m=l=p=0;
            line = stdin.readLine();
               st = new StringTokenizer(line);
               s = Integer.parseInt(st.nextToken());
               t = Integer.parseInt(st.nextToken());
               r = Integer.parseInt(st.nextToken());
               while(l< n){
                   while(l< n && p< t){
                       l+=s;
                       m++;
                       p++;
                   }
                   if(l< n){
                       m+=r;
                       p=0;
                   }
               }
            System.out.println(m);
        }
    }
}

