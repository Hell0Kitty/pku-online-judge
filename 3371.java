/* @author: */
import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.Scanner;
import java.text.DecimalFormat;

class Main
{
  public static boolean isvowel(char a)
  {
     if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y')
      return true;
     else
      return false;
  }

  public static boolean isword(char a)
  {
    if (a==',' || a=='\'' || a=='"')
      return true;
    else
      return false;
   }

  public static boolean issen(char a)
  {
     if (a==':' || a==';' || a=='?' || a=='.' || a=='!')
     return true;
     else
     return false;
  }

  public static void main(String [] args) throws IOException
  {
    Scanner cin=new Scanner(new BufferedInputStream(System.in));
    DecimalFormat df=new DecimalFormat("0.00");
    String inp,temp;
    int word,wordnum=0,sentnum=0,sylnum=0,i,len;
    double score;
    boolean hasaddsyl,hasaddword,hasvow,sinquo,douquo;
    while (cin.hasNext())
    {
    inp=cin.next();
    temp=inp.toLowerCase();
    len=temp.length();
    word=0;
    hasaddsyl=false;
    hasaddword=false;
    hasvow=false;
    sinquo=false;
    douquo=false;
    for (i=0;i< len;i++)
    {
      if (temp.charAt(i)>='a' && temp.charAt(i)<='z')
       {
        word++;
        if ((word<=3) && ((i+1==len) || isword(temp.charAt(i+1)) || issen(temp.charAt(i+1))))
        {
              word=0;
           if (!hasvow)
            sylnum++;
        }
        else if (isvowel(temp.charAt(i)))
        {
           hasvow=true;
           if (!hasaddsyl)
           {
            sylnum++;
            hasaddsyl=true;
           }
           else if (!isvowel(temp.charAt(i-1)))
           {
            if (temp.charAt(i)=='e')
               {
              if (((i+1==len) || (temp.charAt(i+1)>'z') ||
               (temp.charAt(i+1)< 'a')) && (temp.charAt(i-1)=='l'))
             {
               sylnum++;
               continue;
             }
             if ((i+1==len) || ((temp.charAt(i+1)< 'a') || (temp.charAt(i+1)>'z')))
               continue;
             if ((i+1< len) && ((temp.charAt(i+1)=='s') ||
               (temp.charAt(i+1)=='d')) && ((i+2==len) ||
               (temp.charAt(i+2)>'z') || (temp.charAt(i+2)< 'a')))
               continue;
             else
               sylnum++;
            }
            else
              sylnum++;
           }
       }
    }
    else if (isword(temp.charAt(i)))
    {
        hasvow=false;
        if (temp.charAt(i)=='\'' && !sinquo)
        {
             sinquo=true;
          continue;
        }
        if (temp.charAt(i)=='"' && !douquo)
        {
           douquo=true;
           continue;
        }
        wordnum++;
        word=0;
        hasaddword=true;
        hasaddsyl=false;
    }
    else if (issen(temp.charAt(i)))
    {
       wordnum++;
       word=0;
       hasvow=false;
       if ((i+1< len) && temp.charAt(i)=='.' && temp.charAt(i+1)=='.')
        while ((i+1< len) && temp.charAt(i+1)=='.')
             i++;
       else
        sentnum++;
        hasaddword=true;
    }
    }
    if (!hasaddword)
        wordnum++;
  }
  score=206.835-1.015*((double)(wordnum)/(double)(sentnum))-84.6*((double)(sylnum)/(double)(wordnum));
  System.out.println(df.format(score));
 }
}

