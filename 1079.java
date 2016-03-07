import java.io.*;
 public class Main {
  public static int gcd(int a,int b){
   while(a%b!=0){
     int temp=a;
     a=b;
     b=temp%b;
   }
    return b;
}

public static void main(String[] args) throws IOException{
  StreamTokenizer in=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
   while(in.nextToken()!=StreamTokenizer.TT_EOF){
    int a,b;
    double last=100000;
    a=(int)in.nval;	
    in.nextToken();	
    b=(int)in.nval;	
    int devide=gcd(a,b);
     if(devide!=1) {
      a/=devide;
      b/=devide;
     }	
   for(int i=1;i< b;i++) {
     double up=(double)a/((double)b/(double)i);
     int tup1=(int)up;
     int tup2=tup1+1;
     int upf;
    if(Math.abs((double)tup1/i-(double)a/b)< Math.abs((double)tup2/i-(double)a/b))	
	   upf=tup1;
    else upf=tup2;	
    if(Math.abs((double)upf/i-(double)a/b)< last){	
     last=Math.abs((double)upf/i-(double)a/b);	
     System.out.println(upf+"/"+i);	
     }
   }	
    System.out.println(a+"/"+b);
    System.out.println();	
	}

   }
}

