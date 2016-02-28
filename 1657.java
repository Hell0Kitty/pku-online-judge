import java.util.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
        int num = Integer.valueOf(cin.nextLine()).intValue();   
        String[] str = new String[2];   
        String a, b;   
        int x1, y1, x2, y2 = 0;   
        int kr, qr, cr, xr = 0;   
           
        for(int i = 0; i < num; i++)   
//      while(cin.hasNext())   
        {   
            str = cin.nextLine().split(" ");   
            a = str[0];   
            b = str[1];   
            x1 = convert(a.charAt(0));   
            y1 = Integer.valueOf(a.substring(1)).intValue();   
            x2 = convert(b.charAt(0));   
            y2 = Integer.valueOf(b.substring(1)).intValue();               
               
            if(x1==x2 && y1==y2)   
            {   
                System.out.println("0 0 0 0");   
                continue;   
            }   
                   
               
            kr = King(x1, y1, x2, y2);   
            qr = Queen(x1, y1, x2, y2);   
            cr = Che(x1, y1, x2, y2);   
            xr = Xiang(x1, y1, x2, y2);   
            System.out.print(kr + " "    
                    + qr + " " + cr + " ");   
            if(xr == -1)   
                System.out.println("Inf");   
            else  
                System.out.println(xr);   
        }   
  
    }   
       
    private static int convert(char x)   
    {   
        return x-96;   
    }   
  
    private static int King(int x1, int y1, int x2, int y2)   
    {   
        int x = Math.abs(x1 - x2);   
        int y = Math.abs(y1 - y2);   
        if(x > y)   
            return x;   
        else  
            return y;   
    }   
       
    private static int Queen(int x1, int y1, int x2, int y2)   
    {   
        if(x1 == x2 || y1 == y2)   
            return 1;   
        if(directCon(x1, y1, x2, y2) == true)   
            return 1;   
        else  
            return 2;   
    }   
       
    private static int Che(int x1, int y1, int x2, int y2)   
    {   
        if(x1 == x2 || y1 == y2)   
            return 1;   
        else  
            return 2;   
    }   
       
    private static boolean directCon(int x1, int y1, int x2, int y2)   
    {   
        if((x1+y1) == (x2+y2))   
            return true;   
        if((x1-x2) == (y1-y2))   
            return true;   
        return false;   
    }   
       
    private static int Xiang(int x1, int y1, int x2, int y2)   
    {   
        if((x1 + y1)%2 != (x2 + y2)%2)   
            return -1;   
        if(directCon(x1, y1, x2, y2) == true)   
            return 1;   
        return 2;   
    }   
  
}  
