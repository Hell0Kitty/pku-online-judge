import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.StringTokenizer;
public class Main {
    public static void main(String[] args) throws IOException {
        Hashtable< Integer,Integer> table=new Hashtable< Integer,Integer>();
        Hashtable< Integer,Integer> table2=new Hashtable< Integer,Integer>();
               BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        int k=0;
        int n=0;
        int x,c=0,r,temp;
        boolean band;
        ArrayList< Integer> v=new ArrayList< Integer>();
        StringTokenizer t;
       while(stdin.ready()){
           t=new StringTokenizer(stdin.readLine());
            n=new Integer(t.nextToken());
            k=new Integer(t.nextToken());
            table.clear();
            table2.clear();
            v.clear();
            band=true;
            x=k;
            if(x!=0)
            {while(x%2==0){
                x/=2;table.put(2, table.get(2)==null?1:table.get(2)+1);
            }
            c=3;
            while(c<=(Math.sqrt((double)x)+1)){
                if(x%c==0){
                    x/=c;
                    table.put(c, table.get(c)==null?1:table.get(c)+1);
                } else c+=2;
            }
            if(x>1)table.put(x, table.get(x)==null?1:table.get(x)+1);
            }

            band=true;
            v=new ArrayList(table.keySet());
            if(k!=0&&n!=0&&k>n)
            for(int i=0;i< v.size();i++){
                c=table.get(v.get(i));

                x=0;
                r=0;
                while(x< c){
                    r++;
                    temp=r*v.get(i);
                    if(temp>n){
                        band=false;
                        break;
                    }
                    if(table2.get(temp)==null){
                        table2.put(temp,temp);
                    }
                    while(table2.get(temp)%v.get(i)==0){
                        table2.put(temp, table2.get(temp)/v.get(i));
                        x++;
                        if(x==c)break;
                    }
                }
                if(!band) break;
            }
            if(n==0&&k!=1) band=false;
            if(band&&k!=0)System.out.println(k+" divides "+n+"!");
            else System.out.println(k+" does not divide "+n+"!");
        }
    }
}

