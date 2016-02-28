import java.util.*;
import java.math.*;
public class Main {
	public static void main(String []args) throws Exception{

		int i,j,k,n,ans;
		int way[] = new int[100100];
		int flag[] = new int[10100];

		Scanner cin = new Scanner(System.in);

		n = cin.nextInt();
		k = cin.nextInt();

		for(i=0;i<=k;++i) flag[i] = -1;

		for(i=0;i< n;++i) way[i] = cin.nextInt();

		for(i=ans=j=0;i< n;++i){

			if(flag[way[i]]!=ans){
				++j;
				flag[way[i]] = ans;
			}

			if(j>=k){
				++ans;
				j = 0;
			}
		}

		System.out.println(ans+1);
	}
}

