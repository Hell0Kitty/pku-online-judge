import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
		int n=new Integer(stdin.readLine());	
		StringTokenizer tokens;
		int x,y;
		for(int i=0;i<n;i++){
			tokens=new StringTokenizer(stdin.readLine());
			x=new Integer(tokens.nextToken());		
			y=new Integer(tokens.nextToken());
			if(x==y||(x-2)==y)System.out.println(x+y-x%2);
			else System.out.println("No Number");
		}
	}
}
