import java.util.*;
public class Main {
public static void main(String[] args) {
Scanner cin = new Scanner(System.in);
int max_width;
while((max_width=cin.nextInt())!=0){
   int final_width=0;
   int final_height=0;
   int remain=max_width;
   int cur_height=0;
   int r_width=cin.nextInt();
   int r_height=cin.nextInt();
   while(r_width!=-1){
      if(r_width<=remain){
      remain-=r_width;
      if(final_width< max_width-remain)
         final_width=max_width-remain;
      if(cur_height< r_height)
         cur_height=r_height;
      }
      else{
      final_height+=cur_height;
      cur_height=r_height;
      remain=max_width-r_width;
      }
    r_width=cin.nextInt();
    r_height=cin.nextInt();
   }
   if(final_width< max_width-remain)
       final_width=max_width-remain;
   final_height+=cur_height;
   System.out.println(final_width+" x "+final_height);
}
}
}

