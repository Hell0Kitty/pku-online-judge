import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
		int n=new Integer(stdin.readLine());
		String nombre="",winner="";
		int sub,pena,solved,time;
		int maxsolved=0,mintime=0;
		
		StringTokenizer tokens;
		for(int i=0;i<n;i++){
			tokens=new StringTokenizer(stdin.readLine());
			nombre=tokens.nextToken();
			solved=0;
			time=0;
			for(int j=0;j<4;j++){
				sub=new Integer(tokens.nextToken());
				pena=new Integer(tokens.nextToken());
				if(pena!=0){
					solved++;			
					time+=(sub-1)*20+pena;
				}
			}
			if(solved>maxsolved||(solved==maxsolved&&time<mintime)||i==0){
				winner=nombre;
				maxsolved=solved;
				mintime=time;
			}
		}
		System.out.println(winner+" "+maxsolved+" "+mintime);
	}
}
