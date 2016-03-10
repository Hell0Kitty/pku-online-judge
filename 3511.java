//* @author  mekarlos@gmail.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
     public static void main(String args[]) throws IOException{
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens;
        int[] prims=new int[1000001];
        int[] ferms=new int[1000001];
        for(int i=3;i< 1000000;i+=2)
          prims[i]=1;
        prims[2]=1;
        int index=1;
        while((index+=2)< 1000000)
           if(prims[index]==1)
             for(int i=2*index;i< 1000000;i+=index) prims[i]=0;
        ferms[2]=1;
        for(int i=3;i< 1000000;i+=2){
            if(prims[i]==1&&i%4==1) ferms[i]=1;
            prims[i]+=prims[i-1];
            prims[i+1]=prims[i];
            ferms[i]+=ferms[i-1];
            ferms[i+1]=ferms[i];
         }
        int limi=0,lims=0,in,su;
        while(true){
            tokens=new StringTokenizer(stdin.readLine());
            limi=Integer.parseInt(tokens.nextToken());
            lims=Integer.parseInt(tokens.nextToken());
            if(limi==-1&&lims==-1) break;
            in=limi;
            su=lims;
            if(limi<=0) limi=1;
            if(lims<=0) lims=1;
            System.out.println(in+" "+su+" "+(prims[lims]-prims[limi-1])+" "+(ferms[lims]-ferms[limi-1]));
        }
      }
}

