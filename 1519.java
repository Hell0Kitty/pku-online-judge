import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			String number = in.next();
			if (number.equals("0")) {
				break;
			}
			int len = number.length();
			int sum = 0;
			for (int i = 0; i < len; i++) {
				sum += number.charAt(i) - '0';
			}
			int result = sum % 9 == 0 ? 9 : sum % 9;
			System.out.println(result);
		}
	}
}
