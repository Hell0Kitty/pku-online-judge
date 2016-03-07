import java.util.*;
public class Main{
  String result[][];
  char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

  boolean used[];

  public Main(String result[][]){
   this.result=result;
  
  }

   public static void main(String args[]){
    Scanner sc=new Scanner(System.in);

    while(true){
     String result[][]=new String[5][4];
    
    for(int i=0;i<5;i++)
     for(int j=0;j<4;j++){
        if(i>=3)
          result[i][j]="";
        else
          result[i][j]=sc.next();
     }
    
     Main m=new Main(result);
     
     int r=0;
     for(int x=3;x<=4;x++){
       if(!m.doIt(x)){ r+=1; break;}
     }
     if(r==0) m.show();
    }
  }
 
  private void show(){
    for(int i=0;i<5;i++){
     for(int j=0;j<4;j++){
        System.out.print(result[i][j]+" ");
     }
     System.out.println();
    }
    System.out.println();
   }

   
   private boolean ch(String s1,String s2){
     int x=0;
     for(int i=0;i<s1.length();i++)
        for(int j=0;j<s2.length();j++){
          if(s1.charAt(i)==s2.charAt(j)) x++;
          if(x>=2) return true;
        }
     return false;
  }

   private boolean check(StringBuffer temp){
      String s=temp.toString();
       for(int i=0;i<5;i++)
        for(int j=0;j<4;j++){
          if(result[i][j]!=null&&ch(result[i][j],s))
              return false;
        }
       return true;
    }
          
    public boolean doIt(int x){
      used=new boolean[16];
      int sum=0;
      int y=0;
         
    for(int i=0;i<16;i++)
     for(int j=i+1;j<16;j++)
       for(int k=j+1;k<16;k++)
         for(int l=k+1;l<16;l++){
            if(!used[i]&&!used[j]&&!used[k]&&!used[l]){
                StringBuffer s=new StringBuffer("");
                s.append(c[i]).append(c[j]).append(c[k]).append(c[l]);
                if(check(s)){
                    used[i]=true;used[j]=true;used[k]=true;used[l]=true;
                    result[x][y]=s.toString();

                     y=y+1;
                     sum=sum+1;
                }
             }
           }
        if(sum<4){
            System.out.println("It is not possible to complete this schedule.");
            System.out.println();
            return false;
         }
        return true;
    }
      
}