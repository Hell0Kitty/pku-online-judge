import java.util.Scanner;

public class Main {
	private static final int Q = 0;
	public static int[][] array = { { 'B', 'F', 'P', 'V' },
		{ 'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z' }, { 'D', 'T' }, { 'L' },
		{ 'M', 'N' }, { 'R' }, { 'A', 'E', 'I', 'O', 'U', 'H', 'W', 'Y' } };

   public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNext()) {
	String s = in.nextLine();
	String result = "";

	for (int i = 0; i < s.length(); i++) {
               boolean find = false;
		for (int j = 0; j < 7; j++) {
			int len = array[j].length;
			for (int k = 0; k < array[j].length; k++) {
				if (array[j][k] == s.charAt(i)) {
					find = true;
					result += (j + 1);
					break;
				}
			}
			if (find == true)
				break;
		}
	}
	String res = "";
	if (result.charAt(0) < '7')
		res += result.charAt(0);
	for (int i = 1; i < result.length(); i++) {
		if (result.charAt(i) < '7'
			&& result.charAt(i) != result.charAt(i - 1))
			res += result.charAt(i);
	}
	System.out.println(res);
   }
  }
}

