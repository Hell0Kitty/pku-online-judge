import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
public static void main(String[] args)
{
Scanner cin=new Scanner(System.in);
BigDecimal temp,sum,ans,num;
String str;
int i,len;
while(cin.hasNext())
{
str=cin.next();
len=str.length();
temp=BigDecimal.valueOf(8.0);
sum=BigDecimal.ONE;
ans=BigDecimal.ZERO;
for(i=2;i<len;i++)
{
int val=str.charAt(i)-'0';
num=BigDecimal.valueOf(val);
sum=sum.multiply(temp);
ans=ans.add(num.divide(sum));
}
System.out.printf("%s [8] = ",str);
System.out.println(ans+" [10]");
}
}
}
