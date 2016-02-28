import java.util.*;
import java.io.*;

public class Main{
	public static int x,y,z,p,h;
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=scanner.nextInt();
		int m,s;
		String f;
		for (int i=0;i<n ;i++ ){
			m=scanner.nextInt();
			x=y=z=p=0;
			h=2;
			for (int j=0;j<m ;j++ ){
				f=scanner.next();
				s=scanner.nextInt();
				if (f.equals("forward")){
					forward(s);
				}
				else if (f.equals("back")){
					turnLeft();
					turnLeft();
					forward(s);
				}
				else if (f.equals("left")){
					turnLeft();
					forward(s);
				}
				else if (f.equals("right")){
					turnLeft();
					turnLeft();
					turnLeft();
					forward(s);
				}
				else if (f.equals("up")){
					turnUp();
					forward(s);
				}
				else if (f.equals("down")){
					turnUp();
					turnUp();
					turnUp();
					forward(s);
				}
			}
			System.out.println(x+" "+y+" "+z+" "+p);
		}
	}

	public static void turnLeft(){
		if (h==0){
			if (p==2){
				p=1;
			}
			else if (p==1){
				p=5;
			}
			else if (p==5){
				p=4;
			}
			else if (p==4){
				p=2;
			}
		}
		else if (h==3){
			if (p==2){
				p=4;
			}
			else if (p==1){
				p=2;
			}
			else if (p==5){
				p=1;
			}
			else if (p==4){
				p=5;
			}
		}
		else if (h==2){
			if (p==0){
				p=4;
			}
			else if (p==4){
				p=3;
			}
			else if (p==3){
				p=1;
			}
			else if (p==1){
				p=0;
			}
		}
		else if (h==5){
			if (p==0){
				p=1;
			}
			else if (p==4){
				p=0;
			}
			else if (p==3){
				p=4;
			}
			else if (p==1){
				p=3;
			}
		}
		else if (h==1){
			if (p==3){
				p=5;
			}
			else if (p==5){
				p=0;
			}
			else if (p==0){
				p=2;
			}
			else if (p==2){
				p=3;
			}
		}
		else if (h==4){
			if (p==3){
				p=2;
			}
			else if (p==5){
				p=3;
			}
			else if (p==0){
				p=5;
			}
			else if (p==2){
				p=0;
			}
		}
	}

	public static void turnUp(){
		int t=h;
		turnLeft();
		turnLeft();
		h=p;
		p=t;
	}

	public static void forward(int s){
		switch (p){
			case 0:
				x=x+s;
			break;
			case 1:
				y=y+s;
			break;
			case 2:
				z=z+s;
			break;
			case 3:
				x=x-s;
			break;
			case 4:
				y=y-s;
			break;
			case 5:
				z=z-s;
			break;
		
		}
	}
}