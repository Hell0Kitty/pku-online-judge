

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int nc = sc.nextInt();
		sc.nextLine();
		String s = sc.nextLine();
		System.out.println(countSubStr(s, n));

	}

	public static int countSubStr(String s, int subLen) {
		int count = 0;
		int size = s.length();

		HashMap<Integer, Integer> sub = new HashMap<Integer, Integer>(100000);

		int hashCode = 0;
		for (int i = 0; i < size - (subLen - 1); i++) {
			String tmp = s.substring(i, i + subLen);
			hashCode = tmp.hashCode();
			if (sub.get(hashCode) == null) {
				sub.put(hashCode, 1);
				count++;
			}
		}

		return count;
	}

}
