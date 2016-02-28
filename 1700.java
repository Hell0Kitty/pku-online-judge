import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static int sum;

	public static int getSumTime(int[] a, int n) {
		
		if (n < 3) {
			 return a[n-1];
		} else if (n == 3) {
			return a[0] + a[1] + a[2];
		} else {
			int temp1 = a[n-1] + a[0] + a[n - 2] + a[0];
			int temp2 = a[1] + a[0] + a[n-1] + a[1];
			
			if (temp1 < temp2){
				return  temp1 + getSumTime(a, n - 2);
			}
			else if (temp2 < temp1){
				return  temp2 + getSumTime(a, n - 2); 
			}else{
				return  temp2 + getSumTime(a, n - 2); 
			}
		}
	}

	public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          int t = sc.nextInt();
          for(int i = 0; i < t ; i++){
        	  int n = sc.nextInt();
        	  int[] a = new int[n];
        	  for(int j = 0; j < n ; j++){
        		  a[j] = sc.nextInt();
        	  }
        	  Arrays.sort(a);
        	  System.out.println(Main.getSumTime(a, n));
          }     
	}

}
