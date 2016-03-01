//* @author 洪晓鹏<hongxp11@163.com>
import java.util.Scanner;

public class Main {
 public static boolean isPrime(int n) {
	int root = (int) Math.sqrt(n);
	for (int i = 2; i <= root; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int n;
	while ((n = in.nextInt()) != 0) {
		if(n == 4)
		{
			System.out.println(1);
			continue;
		}
		int count = 0;
		for (int i = 3; i <= n / 2; i+=2) {
			if (isPrime(i) && isPrime(n - i)) {
				count ++;
			}
		}
		System.out.println(count);
	}
  }
}

