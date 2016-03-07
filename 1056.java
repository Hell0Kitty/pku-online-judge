import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static boolean isPrefix(String a, String b) {
		int len = a.length() > b.length() ? b.length() : a.length();
		if (a.substring(0, len).equals(b.substring(0, len)))
			return true;
		else
			return false;
	}

	public static void main(String[] args) {
		ArrayList<String> array = new ArrayList<String>();
		Scanner in = new Scanner(System.in);
		int num = 1;
		boolean skip = false;
		while (in.hasNext()) {
			String temp = in.next();
			if (temp.equals("9")) {
				int len = array.size();
				for (int i = 0; i < len - 1; i++) {
					for (int j = i + 1; j < len; j++) {
						if (isPrefix(array.get(i), array.get(j))) {
							skip = true;
						}
					}
				}
				if (!skip) {
					System.out.println("Set " + num
							+ " is immediately decodable");
				} else {
					System.out.println("Set " + num
							+ " is not immediately decodable");
				}
				skip = false;
				num++;
				array.clear();
				continue;
			} else {
				array.add(temp);
			}
		}
	}

}

