import java.util.Scanner; 
import javax.script.ScriptEngine;   
import javax.script.ScriptEngineManager;   
import javax.script.ScriptException; 

public class Main{
    
    ScriptEngineManager factory = new ScriptEngineManager();   
    ScriptEngine engine = factory.getEngineByName("JavaScript");   
    Scanner cin=new Scanner(System.in);
    
    int[] num=new int[60];
    void init()
    {
        for(int i=1;i<59;i++)
            num[i]=i+9997;
    }
    void solve() throws ScriptException
    {
        int numCase=cin.nextInt();
        String s1,s2;
        s1=cin.nextLine();
        for(int k=1;k<=numCase;k++)
        {
            s1=cin.nextLine();
            s2=cin.nextLine();
            for(int i=0;i<52;i++)
            {
                s1=s1.replace(String.valueOf((char)(i+'a')), String.valueOf(num[i+1]));
                s2=s2.replace(String.valueOf((char)(i+'a')), String.valueOf(num[i+1]));    

       
            }
            Object o1= engine.eval(s1);
            Object o2= engine.eval(s2);
            if(o1.toString().endsWith(o2.toString()))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
    public static void main(String[] args) throws ScriptException {   
         Main jason=new Main();
         jason.init();
         jason.solve();
    }   
}
