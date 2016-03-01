import java.util.Scanner;
public class Main {

/**
 * @param args
 */
public static void main(String[] args) {
	// TODO Auto-generated method stub
	Scanner in  = new Scanner(System.in);
	int height = 168;
	int crash = 0;
	for(int i = 0; i< 3; i++){
		int temp = in.nextInt();
		if(temp<=height){
		  System.out.println("CRASH "+temp);
		  crash=1;
		  break;
		}
	}
	if(crash==0)
		System.out.println("NO CRASH");
 }

}

