//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args){
   Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int a,b,c,d;
		int z,nz;
		while (true){
			a=scanner.nextInt();
			b=scanner.nextInt();
			c=scanner.nextInt();
			d=scanner.nextInt();
			if (a+b+c+d==0){
				break;
			}
			if (a*d>b*c){
				z=getN(a,c);
			}
			else{
				z=getN(b,d);
			}
			if (a*c>b*d){
				nz=getN(a,d);
			}
			else{
				nz=getN(b,c);
			}
			if (z< nz){
				if (nz>100){
					nz=100;
				}
				System.out.println(nz+"%");
			}
			else{
				if (z>100){
					z=100;
				}
				System.out.println(z+"%");
			}
		}
	}

	public static int getN(int a,int c){
		return 100*c/a;
	}
}


