import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
  static class complex
  {
    double x, y;
    complex (double x0, double y0)
   {
        x = x0; y = y0;
    }
    complex () { x = 0; y = 0; }
    complex add (complex b)
    {
        return new complex(x + b.x, y + b.y);
    }
    complex minus (complex b)
    {
        return new complex(x - b.x, y - b.y);
    }
    complex multiply (complex b)
    {
        return new complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
    complex divide (complex b)
    {
       return new complex((x * b.x + y * b.y) / (b.x * b.x + b.y * b.y),
                (y * b.x - x * b.y) / (b.x * b.x + b.y * b.y));
    }
   }


   static double distance (complex a, complex b)
    {
       return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
   static final double eps = 1e-12;
   static double total_length;
   static complex [] linepoint = new complex[110];
   static int mvert;
   static complex rate (complex a, complex b, double r)
   {
     return new complex(a.x * (1 - r) + b.x * r,a.y * (1 - r) + b.y * r);
   }

    static complex transport (complex v, complex ori, complex tar)
    {
         complex res = tar.divide(ori);
        return res.multiply(v);
     }

    static complex fractal (int depth, int mdepth, double r)
    {
      double tl = total_length * r;
      for (int i = 1; i < mvert; i++)
       {
          if (Math.abs(tl) < eps) return linepoint[i - 1];
          double d = distance(linepoint[i - 1], linepoint[i]);
         if (tl - d < eps)
          {
            if (depth == mdepth) return rate(linepoint[i - 1], linepoint[i], tl / d);
            else
            {
               complex res = fractal(depth + 1, mdepth, tl / d);
               complex rv = transport(res.minus(linepoint[0]),
                   linepoint[mvert - 1].minus(linepoint[0]),
                   linepoint[i].minus(linepoint[i - 1]));
               return linepoint[i - 1].add(rv);
            }
          }
           else tl -= d;
       }
        return linepoint[mvert - 1];
   }

 public static void main (String args[]) throws Exception
 {
   BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
   String ln = stdin.readLine();
   for (int kase = Integer.parseInt(ln); kase > 0; --kase)
   {
     mvert = Integer.parseInt(stdin.readLine());
     for (int i = 0; i < mvert; i++)
     {
       ln = stdin.readLine();
       StringTokenizer token = new StringTokenizer(ln);
       int x = Integer.parseInt(token.nextToken());
       int y = Integer.parseInt(token.nextToken());
       linepoint[i] = new complex(x, y);
     }
     total_length = 0;
     for (int i = 1; i < mvert; i++) total_length += distance(linepoint[i], linepoint[i - 1]);
     int mdep = Integer.parseInt(stdin.readLine());
     double rt = Double.parseDouble(stdin.readLine());
     complex res = fractal(1, mdep, rt);
     System.out.printf("(%.10f,%.10f)%n", res.x, res.y);
   }
  }
}

