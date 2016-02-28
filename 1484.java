
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		int n, m, c;
		int i, j = 1, k;
		Scanner scanner = new Scanner(System.in);
		boolean blowFuse = false;
		int sumOfPower = 0;
		while(true){
			n = scanner.nextInt();
			m = scanner.nextInt();
			c = scanner.nextInt();
			if(n == 0 && m == 0 && c == 0){
				break;
			}
			sumOfPower = 0;
			int max = 0;
			blowFuse = false;
			Device[] devices = new Device[n + 1];
			for(i = 1; i <= n; i++){
				int num = scanner.nextInt();
				devices[i] = new Device(i, num, false);
			}
			for(i = 1; i <= m; i++){
				k = scanner.nextInt();
				if(devices[k].state && sumOfPower > 0){
					sumOfPower -= devices[k].pow;
					devices[k].state = false;
				}
				else if(!devices[k].state){
					sumOfPower += devices[k].pow;
					devices[k].state = true;
					if(sumOfPower > max){
						max = sumOfPower;
					}
					if(sumOfPower > c){
						blowFuse = true;
					}
				}
			}
			System.out.println("Sequence " + (j++));
			if(blowFuse){
				System.out.println("Fuse was blown.");
			}
			else{
				System.out.println("Fuse was not blown.\nMaximal power consumption was "+ max +" amperes.");
			}
			System.out.println();
		}
		
	}
	static class Device{
		int num;
		int pow;
		boolean state;		// true : power on , false : power in
		public Device(int num, int pow, boolean state){
			this.num = num;
			this.pow = pow;
			this.state = state;
		}
		public boolean equals(Device rhs){
			return(this.num == rhs.num);
		}
	}
}

