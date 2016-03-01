//* @author:
import java.util.*;
public class Main{
 public static void main(String args[]){

  int val[]=new int[10001];

  Scanner in=new Scanner(System.in);
  while(true){
     int n=in.nextInt();
     int k=in.nextInt();
     if(n==-1&&k==-1) break;
     for(int i = 0; i <= n; i++){
         val[i]=in.nextInt();
       }
      for(int i = n; i >= k; i--){
	if (val[i] == 0){
	 continue;
	}
	val[i - k] -= val[i];
	val[i] = 0;
      }
	int s= n;
	while (val[s] == 0 && s > 0){
			s--;
	}
	for (int j = 0; j < s; j++){
          System.out.printf("%d ", val[j]);
	}
	  System.out.printf("%d\n", val[s]);
	}
    }
}

