//* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        Container cn= new Container();
        boolean noSuchCut =false;
        int n = sc.nextInt();
        long m = sc.nextLong();
        Wrapper[] sequence = new Wrapper[n+1];
        sequence[0] = new Wrapper();
        sequence[0].opt = 0;
        sequence[0].num = 0;
        sequence[0].sum = 0;
        sequence[0].k = 0;
        sequence[0].l = 0;
        cn.add(sequence[0]);
        for(int i = 1; i < n+1; i++)
        {
            sequence[i] = new Wrapper();
            sequence[i].num = sc.nextLong();
            if(sequence[i].num > m)
            {
                noSuchCut = true;
            }
            sequence[i].sum += sequence[i].num + sequence[i-1].sum;
            sequence[i].k = i;
        }
        if(noSuchCut)
        {
            System.out.println(-1);
        }else
        {
        int p = n-1;
        int i;
        boolean first =false;
        for(i = n; i >=1; i--)
        {
            for(int j = p; j >= 0; j--)
            {
                if(sequence[i].sum - sequence[j].sum > m)
                {
                    sequence[i].l = j+2;
                    p = j;
                    break;
                }else if(j == 0)
                {
                    sequence[i].l = 1;
                    p = j;
                    first =true;
                    break;
                }
            }
            if(p == 0 && first)
            {
                break;
            }
        }

        for(int j = i - 1; j >= 1; j--)
        {
            sequence[j].l = 1;
        }
        /*
        for(int j = 0; j < n+1; j++)
        {
            System.out.println(sequence[j]);
        }
        */
        for(i = 1; i < n+1; i++)
        {
            cn.add(sequence[i]);
            //System.out.println("----");
            //System.out.println(cn);
            //System.out.println("----");
            long min = sequence[sequence[i].l-1].opt + cn.array[cn.s].num;
            //System.out.println(min);
            for(int j = cn.s; j < cn.e-1; j++)
            {
                long temp = cn.array[j].opt + cn.array[j+1].num;
                if(temp < min)
                {
                    min = temp;
                }
            }
            sequence[i].opt = min;
            //System.out.println(min);
        }
        System.out.println(sequence[n].opt);
    }
    }

}

class Wrapper implements Comparable< Wrapper>
{
    long opt;
    long num;
    long sum;
    int l;
    int k;

    public int compareTo(Wrapper w)
    {
        if(this.num == w.num)
        {
            return 0;
        }else if(this.num > w.num)
        {
            return -1;
        }else
        {
            return 1;
        }
    }
    public String toString()
    {
        return "opt:" + opt + " num:" + num + " sum:" + sum +
                " l:" + l + " k:" + k;
    }
}
class Container
{
    Wrapper[] array;
    int s , e;
    public Container()
    {
        array = new Wrapper[100008];
        s = 0;
        e = 0;
    }
    public void add(Wrapper w)
    {
        int i;
        for(i = s; i < e; i++)
        {
            if(array[i].k >= w.l)
            {
                break;
            }
        }
        s = i;
        for(i = e-1; i >= s; i-- )
        {
            if(array[i].compareTo(w) == -1)
            {
                break;
            }
        }
        array[i+1] = w;
        e = i+2;
    }
    public String toString()
    {
        String result = "";
        for(int i = s; i < e; i++)
        {
            result += array[i].num + " ";
        }
        return result;
    }
}

