//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
class WHO implements Comparable{
    String name;
    int index;
    public int compareTo(Object temp){
        WHO tmp = (WHO)temp;
        if(tmp.index< this.index) return -1;
        return 1;
    }
}
public class Main {
    static final int N = 100000;
    static WHO who[] = new WHO[N];
    static void start(){
        for(int i=0;i< N;++i)
            who[i] = new WHO();
    }

  public static void main(String[]args) throws Exception{
    int i,j,n,t=0;
    start();
    Scanner cin = new Scanner(System.in);
    //Scanner cin = new Scanner(new FileInputStream("input.txt"));
    while(cin.hasNext()){
        n = 0;
        who[n].name = cin.next();
        who[n].name = cin.next();
        while(!who[n].name.equals("END")){
            j = cin.nextInt();
            i = cin.nextInt();
            who[n].index = i-j;
            ++n;
            who[n].name = cin.next();
        }
        Arrays.sort(who,0,n);
        if(t>0) System.out.println();
        for(i=0;i< n;++i)
            System.out.println(who[i].name);
        t = 1;
    }
   }
}

