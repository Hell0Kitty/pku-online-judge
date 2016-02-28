import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		while (true) {
			int student = in.nextInt();
			if (0 == student)
				break;
			int[] candy = new int[student];
			for (int i = 0; i < student; i++) {
				candy[i] = in.nextInt();
			}
			int temp = 0;
			int turns = 0;
			while (true) {
				for (int i = 0; i < student; i++) {

					if (i == 0) {
						temp = (int) Math.ceil(candy[i] * 0.5);
						candy[i] = ((int) Math.ceil(candy[student - 1] * 0.5))
								+ temp;

					}

					else {
						int temp1 = (int) Math.ceil(candy[i] * 0.5);
						candy[i] = (int) Math.ceil(candy[i] * 0.5) + temp;
						temp = temp1;
					}
				}
				turns++;
				int numberOfCandy = candy[0] % 2 == 0 ? candy[0] : candy[0] + 1;
				int count = 0;
				for (int i = 0; i < student; i++) {
					if (candy[i] % 2 == 0 && candy[i] == numberOfCandy)
						count++;
					else if (candy[i] % 2 != 0
							&& (candy[i] + 1) == numberOfCandy)
						count++;
					else
						break;
				}
				if (count == student) {
					System.out.println(turns + " " + numberOfCandy);
					break;
				}
			}
		}
	}

}
