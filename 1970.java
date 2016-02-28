import java.util.Scanner;
public class Main{
 static int p[][]=new int[21][21];
 public static void  main(String args[])
{
  Scanner sc=new Scanner(System.in);
  int tt,i,j,k,x=0,y=0;
  tt=sc.nextInt();
  while((tt--)!=0)
  {

   for(i=1;i< 20;i++)
    for(j=1;j< 20;j++)
	p[i][j]=sc.nextInt();
   int tag=0;
   for(i=1;i< 20;i++)
   {
    for(j=1;j< 16;j++)
    {
	if(p[i][j]==p[i][j-1]) continue;
	if(p[i][j]!=p[i][j+1]) continue;
	if(p[i][j]!=p[i][j+2]) continue;
	if(p[i][j]!=p[i][j+3]) continue;
	if(p[i][j]!=p[i][j+4]) continue;
	if(p[i][j]==p[i][j+5]) continue;
	tag=p[i][j];
	x=i;
	y=j;
	break;
    }
    if(tag!=0) break;
   }

   for(j=1;j< 20;j++)
   {
    if(tag!=0) break;
	for(i=1;i< 16;i++)
	{
	  if(p[i][j]==p[i-1][j]) continue;
	  if(p[i][j]!=p[i+1][j]) continue;
	  if(p[i][j]!=p[i+2][j]) continue;
	  if(p[i][j]!=p[i+3][j]) continue;
	  if(p[i][j]!=p[i+4][j]) continue;
	  if(p[i][j]==p[i+5][j]) continue;
	  tag=p[i][j];
	  x=i;
	  y=j;
	  break;
	}
    }
   for(i=1;i< 16;i++)
   {
    if(tag!=0) break;
    for(j=1;j< 16;j++)
    {
	if(p[i][j]==p[i-1][j-1]) continue;
	if(p[i][j]!=p[i+1][j+1]) continue;
	if(p[i][j]!=p[i+2][j+2]) continue;
	if(p[i][j]!=p[i+3][j+3]) continue;
	if(p[i][j]!=p[i+4][j+4]) continue;
	if(p[i][j]==p[i+5][j+5]) continue;
	tag=p[i][j];
	x=i;
	y=j;
	break;
    }
   }
  for(i=19;i>4;i--)
  {
   if(tag!=0) break;
   for(j=1;j< 16;j++)
   {
	if(p[i][j]==p[i+1][j-1]) continue;
	if(p[i][j]!=p[i-1][j+1]) continue;
	if(p[i][j]!=p[i-2][j+2]) continue;
	if(p[i][j]!=p[i-3][j+3]) continue;
	if(p[i][j]!=p[i-4][j+4]) continue;
	if(p[i][j]==p[i-5][j+5]) continue;
	tag=p[i][j];
	x=i;
	y=j;
	break;
   }
 }
 if(tag==0) System.out.println("0");
 else System.out.printf("%d\n%d %d\n",tag,x,y);
 }
 }
}

