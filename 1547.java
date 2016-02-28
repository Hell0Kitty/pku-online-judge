import java.util.*;   
  
class Clay   
{   
    private int l = 0;   
    private int w = 0;   
    private int h = 0;   
    private String name;   
    private int size = 0;   
       
    public Clay(String l, String w, String h, String name)   
    {   
        this.l = Integer.valueOf(l).intValue();   
        this.w = Integer.valueOf(w).intValue();   
        this.h = Integer.valueOf(h).intValue();   
        this.name = name;   
        this.size = this.l * this.w * this.h;   
    }   
       
    public int getSize()   
    {   
        return size;   
    }   
       
    public String getName()   
    {   
        return name;   
    }   
       
}   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
           
        while(true)   
        {   
            int num = Integer.valueOf(cin.nextLine()).intValue();   
            if(num == -1)   
                break;   
               
            List list = new ArrayList();   
            for(int i = 0; i < num; i++)   
            {   
                String[] str = cin.nextLine().split(" ");   
                Clay clay = new Clay(str[0], str[1], str[2], str[3]);   
                list.add(clay);   
            }   
            Iterator iter = list.iterator();   
            int max = 0;   
            int min = 250;   
            String maxName = null;   
            String minName = null;   
            while(iter.hasNext())   
            {   
                Clay theone = (Clay)iter.next();   
                if(theone.getSize() > max)   
                {   
                    max = theone.getSize();   
                    maxName = theone.getName();   
                }   
                if(theone.getSize() < min)   
                {   
                    min = theone.getSize();   
                    minName = theone.getName();   
                }   
            }   
               
            System.out.println(maxName + " took clay from " + minName + ".");   
        }   
  
    }   
  
}  
