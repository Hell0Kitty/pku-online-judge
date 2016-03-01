//* @author  mekarlos@gmail.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
 public static void main(String[] args) throws IOException {
  BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
   StringTokenizer tokens;
   int din,stu;
   boolean[] st=new boolean[100];
   boolean band;
   while(true){
	tokens=new StringTokenizer(stdin.readLine());
	stu=Integer.parseInt(tokens.nextToken());
	din=Integer.parseInt(tokens.nextToken());
	if(stu==0&&din==0)break;
	for(int i=0;i< stu;i++)st[i]=false;
	for(int i=0;i< din;i++){
		tokens=new StringTokenizer(stdin.readLine());
		for(int j=0;j< stu;j++){
			if(tokens.nextToken().equals("0")){
				st[j]=true;
			}
		}
	}
	band=false;
	for(int i=0;i< stu;i++) {if(!st[i]) band=true;}
	if(band)System.out.println("yes");
	else System.out.println("no");
  }
 }
}

