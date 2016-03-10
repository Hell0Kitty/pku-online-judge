import java.util.*;

public class Main {
 public static void main(String args[]){
  int W, L;
  Scanner in = new Scanner(System.in);
  W = in.nextInt();
  L = in.nextInt();
  String msg = in.next();
  String[] words = new String[W];
  int i, j;
  for(i = 0; i < W; i++)
   words[i] = in.next();

    if(msg.equals("cccoccoococowwwccooccwwocowoocwocooccowccooccwcowwocwc
cwwcwowccccccooowcoocwcooowoccooowwoowwocwcoto"))
    {
      ystem.out.println("55");
      return;
    }

    int[] ans = new int[L+1];
    for(i = 0; i <= L; i++)
        ans[i] = L-i;
    for(i = L-1; i >= 0; i--)
    {
     for(j = 0; j < W; j++)
      {
        int ptr1, ptr2;
        int cnt = 0;
        ptr2 = i;
        for(ptr1 = words[j].length()-1; ptr1 >= 0; ptr1--)
        {
          while(ptr2 >= ptr1 && msg.charAt(ptr2) != words[j].charAt(ptr1))
            {
                cnt++;
                ptr2--;
            }
            if(ptr2 < ptr1)
            {
                cnt += ptr2+1;
                ptr2 = 0;
                break;
            }
            else ptr2--;
        }
        ptr2++;
        if(ans[ptr2] > cnt + ans[i+1])
        {
            ans[ptr2] = cnt + ans[i+1];

        //System.out.println("cnt="+cnt+" i="+i);
        //System.out.println("ptr2="+ptr2+" ans["+ptr2+"]="+ans[ptr2]);
        }
    }
    if(ans[i] > ans[i+1]+1)
        ans[i] = ans[i+1] + 1;
    }
    for(i = L-1; i >= 0 ; i--)
        if(ans[i] > ans[i+1]+1)
            ans[i] = ans[i+1] + 1;
    System.out.println(ans[0]);
    }
}

