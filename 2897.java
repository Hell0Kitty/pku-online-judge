import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{
 public static void main(String[] args) throws IOException{
  BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
    int[] number=new int[100];
    int[] answer=new int[100];
    int count=Integer.parseInt(stdin.readLine()),carry, lastIndex,n,k;
    StringTokenizer token;
    for(int j=0;j< count;j++){
     token=new StringTokenizer(stdin.readLine());
	boolean shouldPrint=false;
	n=Integer.parseInt(token.nextToken());
	k=Integer.parseInt(token.nextToken());
	if(n>k){
		System.out.println(0);
		continue;
	}
	number[99]=k;
	carry=0;
	lastIndex=99;
	for(int i=99;i>=0;i--){
		answer[i]=(number[i]*n+carry)%10;
		carry=(number[i]*n+carry)/10;
		if(answer[i]==k){
			if(carry!=0){
				if(i!=0)number[i-1]=answer[i];

				continue;
			}
			shouldPrint=true;
			lastIndex=i;
			break;
		}
		if(i!=0)number[i-1]=answer[i];

	}
	if(number[lastIndex]==0) shouldPrint=false;
	if(!shouldPrint)System.out.println(0);
	else{
		for(int i=lastIndex;i<=99;i++)	System.out.print(number[i]);
		System.out.println();
	}
    }
  }
}

