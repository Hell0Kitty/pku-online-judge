import java.util.*;
public class Main
{
  //f[i][j]从位置i到位置j所需要插入的最小字符数，ans[i][j]表示i到j之间最少括号匹配字符

 private char s[];
 private int len;

 private  int f[][];
 private String ans[][];

 public Main(char s[]){
     this.s=s;
     this.len=s.length;
     f=new int[len][len];
     ans=new String[len][len];
     for(int i=0;i<len;i++)
         Arrays.fill(ans[i],"");
     dp();
 }

public String[][] getAns(){
    return ans;
}

public String Answer(){
   return ans[0][len-1];
}
   
private void dp()
{
    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++)
        {  
            f[i][j] = Integer.MAX_VALUE;
        }
    for (int i = len - 1; i >= 0; i--)
        for (int j = i; j < len; j++)
            if (i == j)
            {
                f[i][j] = 1;
                if (s[i] == '(') ans[i][j] = "()";
                if (s[i] == ')') ans[i][j] = "()";
                if (s[i] == '[') ans[i][j] = "[]";
                if (s[i] == ']') ans[i][j] = "[]";
            }
            else  if (j > i)
            {
               
                    if (s[i] == '(' && s[j] == ')')
                    {
                        if (f[i + 1][j - 1] < f[i][j])
                        {
                            f[i][j] = f[i + 1][j - 1];
                            ans[i][j] = "(" + ans[i + 1][j - 1] + ")";
                        }
                    }
                    else if (s[i] == '[' && s[j] == ']')
                    {
                        if (f[i + 1][j - 1] < f[i][j])
                        {
                            f[i][j] = f[i + 1][j - 1];
                            ans[i][j] = "[" + ans[i + 1][j - 1] + "]";
                        }                            
                    }
                for (int k = i; k < j; k++)
                {
                    if (f[i][k] + f[k + 1][j] < f[i][j])
                    {
                        f[i][j] = f[i][k] + f[k + 1][j];
                        ans[i][j] = ans[i][k] + ans[k + 1][j];
                    }
                }
            }
}
   
    public static void main(String[] args)
    {
	Scanner sc = new Scanner(System.in);
          String ss=sc.nextLine();
          if(ss.length()==0){
             System.out.println();
          }
         ss.replaceAll(" ", "");
        char s[]=ss.toCharArray();

        Main m=new Main(s);
        System.out.println(m.Answer());
   }
}

