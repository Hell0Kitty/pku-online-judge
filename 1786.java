

import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("N", 0);
		map.put("E", 1);
		map.put("S", 2);
		map.put("W", 3);
		String pos[] = {"N", "E", "S", "W"};
		while(true){
			String dealer = in.next();
			String table[] = new String[4];
			for(int i = 0; i < 4; i++){
				table[i] = "";
			}
			if(dealer.equals("#")){
				return;
			}
			String card = "";
			card += in.next();
			card += in.next();
			
			//System.out.println(card);
			int count = 0;
			int turn = (map.get(dealer) + 1) % 4;
			while(count < 104){
				table[turn] += (card.charAt(count) +""+ card.charAt(count+1));
				count += 2;
				turn = (turn + 1) % 4;
			}
			//System.out.println(card.length());
		//	System.out.println(Arrays.toString(table));
			Card cards[][] = new Card[4][13];
			for(int t = 0; t < 4; t++){
				cards[t] = new Card[13];
				for(int i = 0, j = 0; i < 13; i++, j += 2){
					cards[t][i] = Card.read(table[t].charAt(j), table[t].charAt(j+1));
				}
				Arrays.sort(cards[t]);
			}
			System.out.println("South player:");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[2][i].code + " " + cards[2][i].code);
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("| " + cards[2][i].cc + " ");
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[2][i].code + " " + cards[2][i].code);
			}
			System.out.println("|");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			
			
			System.out.println("West player:");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[3][i].code + " " + cards[3][i].code);
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("| " + cards[3][i].cc + " ");
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[3][i].code + " " + cards[3][i].code);
			}
			System.out.println("|");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			
			System.out.println("North player:");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[0][i].code + " " + cards[0][i].code);
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("| " + cards[0][i].cc + " ");
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[0][i].code + " " + cards[0][i].code);
			}
			System.out.println("|");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
		
			System.out.println("East player:");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[1][i].code + " " + cards[1][i].code);
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("| " + cards[1][i].cc + " ");
			}
			System.out.println("|");
			for(int i = 0; i < 13; i++){
				System.out.print("|" + cards[1][i].code + " " + cards[1][i].code);
			}
			System.out.println("|");
			System.out.println("+---+---+---+---+---+---+---+---+---+---+---+---+---+");
			System.out.println();
		}
	}
}

class Card implements Comparable<Card>{
	int color;
	int num;
	char code;
	char cc;
	public Card(int c, int n, char code, char cc){
		color = c;
		num = n;
		this.code = code;
		this.cc = cc;
	}
	public static Card read(char c, char n){
		int color = -1;
		int num = 0;
		if(c == 'C'){
			color = 0;
		}
		else if(c == 'D'){
			color = 1;
		}
		else if(c == 'S'){
			color = 2;
		}
		else if(c == 'H'){
			color = 3;
		}
		if(Character.isLetter(n)){
			if(n == 'A'){
				num = 14;
			}
			else if(n == 'T'){
				num = 10;
			}
			else if(n == 'J'){
				num = 11;
			}
			else if(n == 'Q'){
				num = 12;
			}
			else if(n == 'K'){
				num = 13;
			}
		}
		else{
			num = n - '0';
		}
		return new Card(color, num, n, c);
	}
	
	public int compareTo(Card rhs){
		if(this.color != rhs.color){
			return this.color - rhs.color;
		}
		else{
			return this.num - rhs.num;
		}
	}
	public String toString(){
		return num + " " + color + " " + code + " " ;
	}
}
