import java.io.*;
import java.util.*;
import java.math.BigInteger;
public  class Main {
 public static void main(String[]args){
  Scanner sin=new Scanner(new BufferedInputStream(System.in));
   int n;
   int i = 0;
   BigInteger big[] = new BigInteger[101];
   for(i = 0 ; i < 101 ; i++)
    big[i] = new BigInteger("0");
    big[0] = big[1].add(new BigInteger("1"));
    big[1] = big[1].add(new BigInteger("1"));
  for(i=2; i < 101 ; i++){
   for(int j = 0 ; j < i ; j++){
    big[i] = big[i].add(big[j].multiply(big[i-1-j]));
   }
}

while(true){
 n=sin.nextInt();
 if(n == -1)break;
   System.out.println(big[n].toString());

}

}
}
:
