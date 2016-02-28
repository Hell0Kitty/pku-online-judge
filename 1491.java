import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.Vector;

public class Main {

	public static int factor(int a, int b) {
		if (b == 0)
			return a;
		else
			return factor(b, a % b);

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if (n == 0)
				break;
			int[] array = new int[n];
			for (int i = 0; i < n; i++) {
				array[i] = in.nextInt();
			}
			int total = (n - 1) * n / 2;
			int count = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (factor(array[i], array[j]) == 1)
						count++;
				}
			}
			if (count == 0)
				System.out.println("No estimate for this data set.");
			else {
				double pi = Math.sqrt(6.0 * total / count);
				DecimalFormat output = new DecimalFormat("#.######");

				System.out.println(output.format(pi));
			}

		}
	}

}
