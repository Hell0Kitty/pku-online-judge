//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {

 static double N = 10000.0;
 public static void main(String []args) throws Exception{

    double temp;
    int i,j,n,m,t=1;
    Map first = new HashMap();
 StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    in.nextToken();n=(int)in.nval;//n = cin.nextInt();
    for(i=0;i< n;++i){
        in.nextToken();
        first.put(in.nval,1);
        //first.put(cin.nextDouble(), 1);
    }
    j = 0;
    //m = cin.nextInt();
    in.nextToken();m =(int)in.nval;

    for(i=0;i< m;++i){
        in.nextToken();
        temp = in.nval;
        //temp = cin.nextDouble();
        temp = N-temp;
        if(first.containsKey(temp)){
            j = 1;
            break;
        }
    }

    if(j==1) System.out.println("YES");
    else System.out.println("NO");

  }
}

