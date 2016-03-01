import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class Main{
 static Scanner cin;

 static double ci = 2.09, cw = 4.19;
 static double em = 335;

 public static void main(String args[]){
	cin = new Scanner(System.in);
	while(run())
			;
 }

 static boolean run(){
  double mw = cin.nextDouble();
  double mi = cin.nextDouble();
  double tw = cin.nextDouble();
  double ti = cin.nextDouble();

  if((mw+mi)==0)
	return false;

  DecimalFormat df = new DecimalFormat("#0.0");

  double Energy = waterEnergy(mw, tw)+iceEnergy(mi, ti);
  double averE = Energy/(mw+mi);

  double iceThreshold = ci*30;
  double waterThreshold = iceThreshold+em;

  if(averE <= iceThreshold){
    double temp = -30+averE/ci;
    System.out.println(df.format(mw+mi)+" g of ice and 0.0 g of water at "+df.format(temp)+" C");
  }
  else if(averE < waterThreshold){
   double fmw = (mw+mi)*(averE-iceThreshold)/em;
   double fmi = mw+mi-fmw;
   System.out.println(df.format(fmi)+" g of ice and "+df.format(fmw)+" g of water at 0.0 C");
  }
  else{
   double temp = (averE-waterThreshold)/cw;
   System.out.println("0.0 g of ice and "+df.format(mw+mi)+" g of water at "+df.format(temp)+" C");
  }

  return true;

}

static double waterEnergy(double mw, double tw){
  double waterThreshold = ci*30+em;
  return mw*(waterThreshold+tw*cw);
 }

static double iceEnergy(double mi, double ti){
	return mi*(ti+30)*ci;
 }
}

