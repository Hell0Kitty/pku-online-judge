//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
  {
   String s=in.nextLine();
   StringBuffer sb=new StringBuffer("");
   int l=s.length();
   boolean bb=false;
   for(int i=0;i< l;i++)
   {
    char c=s.charAt(i);
    if(i< l-1&&c=='d'&&s.charAt(i+1)=='d'){
        sb.append('p');
        i++;
    }
    else if(i< l-1&&c=='e'&&s.charAt(i+1)=='i'&&(i==0||s.charAt(i-1)!='c')){
        sb.append("ie");
        i++;
    }
    else if(i< l-3&&c=='p'&&s.charAt(i+1)=='i'&&s.charAt(i+2)=='n'&&s.charAt(i+3)=='k'){
        sb.append("floyd");
        i+=3;
    }
    else if(i< l-2&&c=='E'&&s.charAt(i+1)=='O'&&s.charAt(i+2)=='F'){
        bb=true;
        break;
    }
    else if(c>='a'&&c<='z'||c==' ') sb.append(c);
    }
    System.out.println(sb);
    if(bb) break;
   }
 }
}

