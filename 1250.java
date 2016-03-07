import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int num = in.nextInt();
			if (num == 0)
				break;
			String customers = in.next();
			int leftCustomer = 0;
			Set<Character> customerSet = new HashSet<Character>();
			for (int i = 0; i < customers.length(); i++) {
				int size = customerSet.size();
				if (size >= num) {
					if (customerSet.contains(customers.charAt(i))) {
						customerSet.remove(customers.charAt(i));
						continue;
					}
					leftCustomer++;
					int index = customers.indexOf(customers.charAt(i), i + 1);
					if (index != -1)
						customers = customers.substring(0, index)
								+ customers.substring(index + 1);
				} else {
					if (customerSet.contains(customers.charAt(i))) {
						customerSet.remove(customers.charAt(i));
					} else
						customerSet.add(customers.charAt(i));
				}
			}
			if (leftCustomer == 0)
				System.out.println("All customers tanned successfully.");
			else
				System.out.println(leftCustomer + " customer(s) walked away.");
		}
	}
}
