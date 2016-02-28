public class Main
{
 public static void main(String[] args)	{

    int i, n, j;
    double e = 0;
 
    System.out.printf("n e\n- -----------\n");
    for (n = 0; n <= 9; ++n)
    {
        i = 1;
        for (j = 1; j <= n; ++j)
            i *= j;
        e += 1.0 / i;
        System.out.printf("%d %10.9f\n", n, e);
    }

  }
}