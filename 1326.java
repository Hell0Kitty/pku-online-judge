import java.util.*;   
import java.text.*;   
  
class FRecord   
{   
    String from;   
    String to;   
    int miles;   
    String type;   
       
    public FRecord(String a, String b, int c, String d)   
    {   
        this.from = a;   
        this.to = b;   
        this.miles = c;   
        this.type = d;   
    }   
       
}   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
        ArrayList record = new ArrayList();   
           
        while(true)   
        {   
            String tmp = cin.nextLine();   
               
            if(tmp.equals("#"))   
                break;   
            else if(tmp.equals("0"))   
            {   
                int total = getSummary(record);   
                record.clear();   
                System.out.println(total);   
            }   
            else  
            {   
                String[] str = tmp.split(" ");   
                FRecord fr = new FRecord(str[0], str[1],    
                        Integer.valueOf(str[2]).intValue(), str[3]);   
                record.add(fr);   
            }   
        }   
    }   
       
    private static int getSummary(ArrayList record)   
    {   
        int result = 0;   
           
        Iterator iter = record.iterator();   
        while(iter.hasNext())   
        {   
            FRecord fr = (FRecord)iter.next();   
            if(fr.type.equals("F"))   
            {   
                result += fr.miles * 2;   
                DecimalFormat df = new DecimalFormat("#");   
                result = Integer.valueOf(df.format(result)).intValue();   
            }   
            else if(fr.type.equals("B"))   
            {   
                result += fr.miles;   
                result += (fr.miles + 1)/2;   
                DecimalFormat df = new DecimalFormat("#");   
                result = Integer.valueOf(df.format(result)).intValue();   
            }   
                   
            else  
            {   
                if(fr.miles > 500)   
                {   
                    result += fr.miles;   
                    DecimalFormat df = new DecimalFormat("#");   
                    result = Integer.valueOf(df.format(result)).intValue();   
                }   
                       
                else  
                {   
                    result += 500;   
                    DecimalFormat df = new DecimalFormat("#");   
                    result = Integer.valueOf(df.format(result)).intValue();   
                }   
                       
            }   
        }   
           
        return result;   
    }   
  
}  
