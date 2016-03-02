import java.util.Arrays;
import java.util.Scanner;

public class Main {

//	private static int ans[] =new int[100000];
	private static int index = 0;
	public static void get(int[] seq, int s , int[]ans) {
		int sum = 0;
	    int k = 0;
	    int len = 0;
		for (int i = 0 ; i = s){
				for(int j = k ;j< i;j++ ){
					int temp = sum - seq[j];
					if(temp >= s){
						sum = temp;
						len --;
					}else{
						k = j;
						ans[index++] = len;
						break;
					}
				}
			}

		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int testNum = sc.nextInt();

		for (int i = 0; i < testNum; i++) {

			int n = sc.nextInt();
			int s = sc.nextInt();
			int[] seq = new int[n];
            int[] ans = new int[n];
            index = 0;
			for (int j = 0; j < n; j++) {
				seq[j] = sc.nextInt();
			}
			get(seq, s , ans);
			//Arrays.sort(seq);
	        Arrays.sort(ans , 0 ,index);
	        System.out.println(ans[0]);
		}

	}

}

