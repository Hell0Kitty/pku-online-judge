import java.util.*;
public class Main {
Scanner cin = new Scanner(System.in);

int n;
int k;
int[] coin;
int[] numsOfNotEqual;
int[] numsOfEqual;
int[] numsLight;
int[] numsHeavy;
int notEqual;
int equal;
char c;
int p;

public void inPut() {
   n = cin.nextInt();
   k = cin.nextInt();
   coin = new int[n];
   numsOfEqual = new int[n];
   numsOfNotEqual = new int[n];
   numsLight = new int[n];
   numsHeavy = new int[n];

   for (int i = 0; i < k; i++) {
    p = cin.nextInt();
    for (int j = 0; j < 2 * p; j++) {
     coin[j] = cin.nextInt();
    }
    c = cin.next().charAt(0);

    judge();
   }
   int res = 0;
   int resnum = 0;
   for (int i = 0; i < n; i++) {
    if (numsOfEqual[i] == 0) {
     if (numsOfNotEqual[i] == notEqual) {
      if(numsLight[i] == notEqual || numsHeavy[i] == notEqual) {
       res = i + 1;
       resnum ++;
      } 
     }
    }
   }
   if(resnum == 1) {
    System.out.println(res);
   } else {
    System.out.println(0);
   }
}

private void judge() {
   if (c == '=') {
    for (int i = 0; i < p * 2; i++) {
     numsOfEqual[coin[i] - 1]++;
    }
    equal++;
   } else {
    notEqual++;

    if (c == '<') {
     for (int i = 0; i < p * 2; i++) {
      numsOfNotEqual[coin[i] - 1]++;
      if(i < p) {
       numsLight[coin[i] - 1] ++; 
      } else {
       numsHeavy[coin[i] - 1] ++;
      }
     }
    
    } else {
     for(int i = 0; i < p * 2; i ++) {
      numsOfNotEqual[coin[i] - 1] ++;
      if(i >= p) {
       numsLight[coin[i] - 1] ++; 
      } else {
       numsHeavy[coin[i] - 1] ++;
      }
     }
    }
   }
}

public static void main(String[] args) {
   new Main().inPut();
}
}
