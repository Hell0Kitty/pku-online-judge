//* @author  mekarlos@gmail.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(stdin.readLine()),k,aux;
		StringTokenizer tokens;
		while((n--)!=0){
			tokens=new StringTokenizer(stdin.readLine());
			k=Integer.parseInt(tokens.nextToken());
			aux=-k+1;
			while((k--)!=0)aux+=Integer.parseInt(tokens.nextToken());
			System.out.println(aux);
		}
	}
}

