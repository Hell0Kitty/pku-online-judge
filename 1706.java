import java.util.*;
import java.io.*;

public class Main 
{
    public static Map<Integer,Integer> mapOldToNew;
    public static Map<Integer,Integer> mapNewToOld;    
    public static int counter = 1;
    public static void main(String[] args) throws Exception
    {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        Map<Integer, StringBuilder> references = new HashMap<Integer,StringBuilder>(1000);
        mapOldToNew = new HashMap<Integer,Integer>(1000);
        mapNewToOld = new HashMap<Integer,Integer>(1000);
        boolean isInsidePara = false;
        boolean isRegPara = true;
        boolean isBegin = true;
        String num = "";
        String line = null;
        StringBuilder para = null;
        String id = "";
        while(true)
        {
            line = stdin.readLine();
            if(line == null)
            {
                break;
            }
            if(line.trim().length() == 0)
            {
                if(isInsidePara)
                {
                    isInsidePara = false;
                    if(isRegPara)
                    {
                        //regulars[numReg++] = para;
                    }else
                    {
                        int in = Integer.parseInt(id);
                        references.put(in,para);
                    }
                }
            }else
            {
                if(!isInsidePara)
                {
                    isInsidePara = true;
                    if(line.startsWith("["))
                    {
                        
                        para = new StringBuilder(240);
                        isRegPara = false;
                        id = "";
                        for(int i = 1; i < line.length(); i++)
                        {
                            char ch = line.charAt(i);
                            if(ch == ']')
                            {
                                break;
                            }
                            id += ch;
                        }
                        para.append(line);
                        para.append("\n");
                    }else
                    {
                        isRegPara= true;
                        if(isBegin)
                        {
                            isBegin = false;
                        }else
                        {
                            System.out.write('\n');
                        }
                        printRegLine(line);
                    }
                }else
                {
                    if(isRegPara)
                    {
                        printRegLine(line);
                    }else
                    {
                        para.append(line);
                        para.append("\n");
                    }
                }
            }
        }
        
        if(isInsidePara)
        {
            if(isRegPara)
            {
                //regulars[numReg++] = para;
            }else
            {
                int in = Integer.parseInt(id);
                references.put(in,para);
            }
        }
        
        boolean insideRef = false;
        for(int j = 1; j < counter; j++)
        {
            StringBuilder sb = references.get(mapNewToOld.get(j));
            System.out.write('\n');
            
            num = "";
            insideRef = false;
            for(int i = 0; i < sb.length(); i++)
            {
                char ch = sb.charAt(i);
                if(ch == '[')
                {
                    insideRef = true;
                    System.out.write(ch);
                }else if(ch == ']')
                {
                    insideRef = false;
                    int in = Integer.parseInt(num);
                    num = "";
                    System.out.print(mapOldToNew.get(in));
                    System.out.write(ch);
                }else if(insideRef)
                {
                    num += ch;
                }else
                {
                    System.out.write(ch);
                }
            }
        }
    }
    
    public static void printRegLine(String sb)
    {
            String num = "";
            boolean insideRef = false;
            for(int i = 0; i < sb.length(); i++)
            {
                char ch = sb.charAt(i);
                if(ch == '[')
                {
                    insideRef = true;
                    System.out.write(ch);
                }else if(ch == ']')
                {
                    insideRef = false;
                    int in = Integer.parseInt(num);
                    Integer value = mapOldToNew.get(in);
                    if(value == null)
                    {
                        mapOldToNew.put(in,counter);
                        mapNewToOld.put(counter,in);
                        counter++;
                    }
                    num = "";
                    System.out.print(mapOldToNew.get(in));
                    System.out.write(ch);
                }else if(insideRef)
                {
                    num += ch;
                }else
                {
                    System.out.write(ch);
                }
            }
            System.out.write('\n');
    }
}
