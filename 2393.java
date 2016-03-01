import java.util.Scanner;

public class Main{

public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   int n = cin.nextInt();
   int m = n;
   int s = cin.nextInt();
   Node[] node = new Node[n];
   int i = 0;
   long sum = 0;
   while(m > 0) {
    node[i] = new Node(cin.nextInt(), cin.nextInt());
    i++;
    m--;
   }
   for(i=0; i< n-1; i++) {
    if(node[i].c + s < node[i+1].c) {
     node[i+1].c = node[i].c + s;
    }
     sum += node[i].c * node[i].y;
   }
   sum += node[i].c * node[i].y;
   System.out.println(sum);
}

}

class Node {
int c;
int y;
public Node(int c, int y) {
   this.c = c;
   this.y = y;
}
}

