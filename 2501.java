import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class Main
{
    static int hh;
    static int mm;
    static int ss;
    static double sumDist;
    static double speed;
    public static void main(String[] args) throws Exception
    {
        readFile();
    }

    static void readFile() throws Exception
    {
        BufferedReader br = new BufferedReader(
            //new FileReader("in.in"));
            new InputStreamReader(System.in));
        StringTokenizer st = null;
        String stemp = null;
        while((stemp=br.readLine())!=null)
        {
            st = new StringTokenizer(stemp," ");
            if(st.countTokens()==2)
            {
                stemp = st.nextToken();
                double tempspeed = Double.valueOf(st.nextToken()) / 3600;
                st = new StringTokenizer(stemp,":");
                process(Integer.valueOf(st.nextToken()),
                    Integer.valueOf(st.nextToken()),
                    Integer.valueOf(st.nextToken()),-1);
                speed = tempspeed;
            }
            else
            {
                st = new StringTokenizer(st.nextToken(),":");
                process(Integer.valueOf(st.nextToken()),
                    Integer.valueOf(st.nextToken()),
                    Integer.valueOf(st.nextToken()),1);
            }
        }
    }
    static int fff = 0;

    static void process(int h,int m,int s,int flag)
    {
        int sumSecond = 0;
        sumSecond += (s-ss);
        sumSecond += ((m-mm)*60);
        sumSecond += ((h-hh)*3600);
        sumDist += (sumSecond * speed);
        if(flag==1)
        {
            if(fff!=0)
                System.out.println();
            fff++;
            display(h,m,s);
            System.out.print(saveDigit(sumDist,2));
            System.out.print(" km");
        }
        hh = h;
        mm = m;
        ss = s;
    }

    static String saveDigit(double d,int n)
    {
        StringBuffer sb = new StringBuffer("###.");
        for(int i=0; i< n; i++)
            sb.append("0");
        DecimalFormat df2  = new DecimalFormat(sb.toString());
        StringBuffer result = new StringBuffer(df2.format(d));
        if(result.indexOf(".")==0)
            result.insert(0,"0");
        return result.toString();
    }

    static void display(int h,int m,int s)
    {
        if(h< 10)
            System.out.print("0");
        System.out.print(h+":");
        if(m< 10)
            System.out.print("0");
        System.out.print(m+":");
        if(s< 10)
            System.out.print("0");
        System.out.print(s+" ");
    }
}

