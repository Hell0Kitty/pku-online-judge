import java.util.*;
import java.math.*;
public class Main {
  static int S, H;
  static int []h = new int [51];
  //static Hatch []p = new Hatch [51];
  static int []x = new int [51];
  static int []y = new int [51];
  static void deal()
  {
   int i, j, k;
   double dist, temp;
   for (i = 0; i <= S; i++)
   {
    k = 1;
    for (j = 0; j <= S; j++)
    {
  dist = -1;
  for (k = 0; k < H; k++)
  {
     if (i == x[k] && j == y[k])
    break;
     temp = Math.sqrt((double)((i - x[k]) * (i - x[k]) + (j - y[k]) * (j - y[k])));
     dist = Math.max(dist, temp);
  }
  if (k < H || dist > S - i || dist > i || dist > S - j || dist > j)
      continue;
  System.out.println(i + " " + j);
    return;
     }
    }
    System.out.println("poodle");
 }

  static void input()
  {
    int N, i;
    Scanner cin = new Scanner (System.in);
    N = cin.nextInt();
    while (N > 0)
    {
  S = cin.nextInt();
  H = cin.nextInt();
  for (i = 0; i < H; i++)
  {
     x[i] = cin.nextInt();
     y[i] = cin.nextInt();
  }
  deal();
  N--;
    }
  }

public static void main (String []args)
{
  input();
 }
}