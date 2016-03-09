/* @author:zeropinzuo */
import java.io.*;
import java.util.*;

public class Main{
 static Scanner cin;
 public static void main(String args[]){
  cin = new Scanner(System.in);
  int n = cin.nextInt();
  for(int i=0;i< n;i++)
   run();
  }

 static void run(){
   Card card = new Card(cin);
   boolean first=true;
   int n;
   for(int i=0;i< 75;i++){
    n = cin.nextInt();
    if(first==true){
    card.mark(n);
    if(card.check()==true){
      System.out.println("BINGO after "+(i+1)+" numbers announced");
      first = false;
    }
    }
   }
 }
}

class Card{
 int[][] map;
 boolean[][] marked;

 public Card(Scanner cin){
  int size=5;
  map = new int[size][size];
  marked = new boolean[size][size];

  int i,j;
  for(i=0;i< size;i++)
   for(j=0;j< size;j++){
     marked[i][j] = false;
     if((i!=2)||(j!=2))
    map[i][j] = cin.nextInt();
    }
   marked[2][2] = true;
 }

 void mark(int n){
   int row=0, column=0;

   while(row< 5){
    column=0;
    while(column< 5){
    if(map[row][column]==n){
      marked[row][column] = true;
      break;
    }
       column++;
     }

    if(column< 5)
    break;
    row++;
   }
 }

 boolean check(){
   if(checkRow())
    return true;
   else if(checkColumn())
    return true;
   else if(checkDiagonal())
    return true;
  else
    return false;
}

boolean checkRow(){
 int row=0;
 while(row< 5){
   int column=0;
   while(column< 5){
    if(marked[row][column]==false)
        break;
    column++;
   }

  if(column==5){
    break;
   }
   row++;
 }

 if(row< 5){
   return true;
  }
 return false;
}

 boolean checkColumn(){
    int column=0;
    while(column< 5){
    int row=0;
    while(row< 5){
      if(marked[row][column]==false)
       break;
      row++;
    }

    if(row==5)
      break;
    column++;
    }

    if(column< 5)
    return true;
    return false;
 }


 boolean checkDiagonal(){
   if(checkLeftDiagonal())
     return true;
   else if(checkRightDiagonal())
     return true;
   else
     return false;
  }

 boolean checkLeftDiagonal(){
   int element=0;
   while(element< 5){
     if(marked[element][element] == false)
         return false;
     element++;
   }
   return true;
 }

boolean checkRightDiagonal(){
  int element=0;
  while(element< 5){
   if(marked[element][4-element] == false)
    return false;
   element++;
  }
 return true;
 }
}

