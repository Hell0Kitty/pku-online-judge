import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        Hashtable< String,String> table = new Hashtable< String, String>();
        String s="";
        StringTokenizer token;
        while(true){
            s=stdin.readLine();
            if(s.equals(""))break;
            token=new StringTokenizer(s);
            s=token.nextToken();
            table.put(token.nextToken(),s);
        }
        while(stdin.ready()){
           s=stdin.readLine();
         if(table.get(s)!=null)System.out.println(table.get(s));
         else System.out.println("eh");
        }
    }
}

