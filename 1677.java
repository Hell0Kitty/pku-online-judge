/**
 * pku 1677 Girls' Day
 * Memory: 3524K  Time: 172MS 
 * Language: Java  Result: Accepted 
 * @Author	conanhjj
 */
import java.util.*;

public class Main {

	static Scanner in = new Scanner(System.in);

	static int g,w;
	static String[] girl;

	public static void main(String[] args){
		input();
		work();
	}

	static void work() {
		String line;
		for(int i=0;i<w;++i){
			do{
				line = in .nextLine();
			}while(line.length()==0);

			LinkedList<String> words = new LinkedList<String>(Arrays.asList(line.split("[\\s|!]+")));
			if(words.size()>0 && words.peek().equals(""))
				words.removeFirst();

		//	System.out.println(words);

			boolean flag = false;
			boolean xixi = false;
			boolean[] mark = new boolean[g];
			for(int k=0;k<mark.length;++k) mark[k] =false;

			for(String word : words){
				word = word.toLowerCase();

				if(word.equals("beautiful") || word.equals("pretty") ||
						word.equals("lovely")){
					xixi = true;
				}

				for(int k=0;k<g;++k) {
					if(word.equals(girl[k]) && !mark[k]){
						mark[k] = true;
						flag = true;
					}
				}
			}

			if(!flag){
				System.out.print("All");
			} else {
				boolean first = true;
				for(int k=0;k<g;++k) {
					if(mark[k]){
						if(first){
							System.out.print(girl[k]);
							first = false;
						} else {
							System.out.print(" " + girl[k]);
						}
					}
				}
			}

			System.out.print(": ");

			if(words.size() <= 9 ){
				System.out.println("oh");
			} else {
				if(xixi){
					System.out.println("xixi");
				} else {
					System.out.println("hehe");
				}
			}


		}


	}

	static void input(){
		g = in.nextInt();
		w = in.nextInt();

		girl = new String[g];
		for(int i=0;i<g;++i){
			girl[i] = in.next();
			//System.out.println(girl[i]);
		}
	}
}

