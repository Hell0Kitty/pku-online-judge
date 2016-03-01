import java.io.*;
import java.util.*;

public class Main {

/**
 * @param args
 */
public static void main(String[] args)throws Exception {
	// TODO Auto-generated method stub
	int a,b,c,d,t,i;

	Scanner cin = new Scanner(System.in);

	t = cin.nextInt();
	for(i=1;i<=t;++i){
		a = cin.nextInt();
		b = cin.nextInt();
		c = cin.nextInt();
		d = cin.nextInt();

		System.out.print("Scenario #"+i);
		System.out.println(":");
		if((a+b+c+d)%2==1)
			System.out.println("1");
		else
			System.out.println("0");
		System.out.println("");
	}
  }

}

